/**
 * Modulate audio file
 */

/*==================================
 * Includes
 *==================================*/

#include "modulate.h"

 /*==================================
 * Constants
 *==================================*/

const double filterCoef[FLT_LEN] = {0.00784720566823818, -0.0221600583712072,
  -0.0327523008959209, 0.0545434154471652, 0.105245431756392,
  -0.0680365450748197, -0.191896904619835, 0.0314051909990713,
  0.230985188648533, 0.0314051909990713, -0.191896904619835,
  -0.0680365450748197, 0.105245431756392, 0.0545434154471652,
  -0.0327523008959209, -0.0221600583712072, 0.00784720566823818};

/*==================================
 * Public
 *==================================*/

void filter(double data[], uint32_t dataLen) {
	
  // Init past value buffer to 0, this is effectively zero padding the data
  double pastBuf[FLT_LEN] = {0};

  // Keep track of buffer index which rotates through buffer
  uint16_t bufIndex = 0;

  // Iterate through all terms
  uint16_t i, j;
  for (i = 0; i < dataLen; i++) {

    // Place cur term in buf at most recent pos
    bufIndex = i % FLT_LEN;
    pastBuf[bufIndex] = data[i];

    // Perform filter on current buffer
    double filteredValue = 0;
    uint16_t k;
    for (j = 0; j < FLT_LEN; j++) {

      /*
       * The bufIndex is the starting point. The pastBuf has
       * values added to the right, so iterate left from the starting
       * point to iterate through successively older values.
       * Add FLT_LEN so that this index doesn't go negative.
       */
      k = (FLT_LEN + bufIndex - j) % FLT_LEN;

      // BPF coefficients are ordered new to old
      filteredValue += pastBuf[k] * filterCoef[j];
    }

    // Update data
    data[i] = filteredValue;
  }
}
