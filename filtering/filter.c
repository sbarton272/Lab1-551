/**
 * Filter audio file
 */

/*==================================
 * Includes
 *==================================*/

#include "filter.h"

 /*==================================
 * Constants
 *==================================*/

const static double filterCoef[FILTER_FLT_LEN] = {
  -0.000837033934143375, 0.00435464024061718, 0.00226374006007626,
  -0.00459454064494268, -0.00444055887816762, 0.00474733658344885,
  0.00768157600178255, -0.00400670848495919, -0.0118322326930983,
  0.00155235141792176, 0.0162355001351293, 0.00317855974186010,
  -0.0198367626566760, -0.0102642009210608, 0.0214081573104826,
  0.0191756052039397, -0.0198432153773508, -0.0287960305512720,
  0.0144537345195093, 0.0375867498629513, -0.00519752867326147,
  -0.0438692666638967, -0.00722089152217358, 0.0461655172861916,
  0.0214073907536954, -0.0435220206827874, -0.0354886827619457,
  0.0357450073359796, 0.0474370150901666, -0.0234913113144946,
  -0.0554432339431620, 0.00819040743675582, 0.0582601524177672,
  0.00819040743675582, -0.0554432339431620, -0.0234913113144946,
  0.0474370150901666, 0.0357450073359796, -0.0354886827619457,
  -0.0435220206827874, 0.0214073907536954, 0.0461655172861916,
  -0.00722089152217358, -0.0438692666638967, -0.00519752867326147,
  0.0375867498629513, 0.0144537345195093, -0.0287960305512720,
  -0.0198432153773508, 0.0191756052039397, 0.0214081573104826,
  -0.0102642009210608, -0.0198367626566760, 0.00317855974186010,
  0.0162355001351293, 0.00155235141792176, -0.0118322326930983,
  -0.00400670848495919, 0.00768157600178255, 0.00474733658344885,
  -0.00444055887816762, -0.00459454064494268, 0.00226374006007626,
  0.00435464024061718, -0.000837033934143375};

/*==================================
 * Public
 *==================================*/

void filter(double data[], uint32_t dataLen) {
	
  // Init past value buffer to 0, this is effectively zero padding the data
  double pastBuf[FILTER_FLT_LEN] = {0};

  // Keep track of buffer index which rotates through buffer
  uint32_t bufIndex = 0;

  // Iterate through all terms
  uint32_t i, j;
  for (i = 0; i < dataLen; i++) {

    // Place cur term in buf at most recent pos
    bufIndex = i % FILTER_FLT_LEN;
    pastBuf[bufIndex] = data[i];

    // Perform filter on current buffer
    double filteredValue = 0;
    uint32_t k;
    for (j = 0; j < FILTER_FLT_LEN; j++) {

      /*
       * The bufIndex is the starting point. The pastBuf has
       * values added to the right, so iterate left from the starting
       * point to iterate through successively older values.
       * Add FLT_LEN so that this index doesn't go negative.
       */
      k = (FILTER_FLT_LEN + bufIndex - j) % FILTER_FLT_LEN;

      // BPF coefficients are ordered new to old
      filteredValue += pastBuf[k] * filterCoef[j];
    }

    // Update data
    data[i] = filteredValue;
  }
}
