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

const float filterCoef[FLT_LEN] = {5, 8, 8, 4, -4, -9, 0, 17, 16,
	-30, -121, -210, -220, -101, 116, 327, 415, 327, 116, -101, -220,
	-210, -121, -30, 16, 17, 0, -9, -4, 4, 8, 8, 5};


/*==================================
 * Public
 *==================================*/

void filter(float data[], uint16_t dataLen) {
	
  // Init past value buffer to 0, this is effectively zero padding the data
  float pastBuf[FLT_LEN] = {0};

  // Keep track of buffer index which rotates through buffer
  uint16_t bufIndex = 0;

  // Iterate through all terms
  uint16_t i, j;
  for (i = 0; i < dataLen; i++) {

    // Place cur term in buf at most recent pos
    bufIndex = i % FLT_LEN;
    pastBuf[bufIndex] = data[i];

    // Perform filter on current buffer
    float filteredValue = 0;
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
      filteredValue += pastBuf[k] * filterCoef[j]);
    }

    // Update data
    data[i] = filteredValue;
  }
}
