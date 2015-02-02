/**
 * Filter audio
 * - Load file
 * - Filter
 * - Save file
 */

#ifndef _FILTER_H
#define _FILTER_H

/*==================================
 * Includes
 *==================================*/

#include <stdio.h>
#include <inttypes.h>

/*==================================
 * Macros
 *==================================*/

// Calculated from matlab.
#define FLT_LEN 33

extern const float filterCoef[FLT_LEN];

/*==================================
 * Public
 *==================================*/

 /*
 * Apply the predetermined filter to the data.
 * NOTE This destructively modifies data.
 */
void filter(float data[], uint16_t dataLen);

#endif // _FILTER_H