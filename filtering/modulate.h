/**
 * Amplitude modulate audio
 */

#ifndef _MODULATE_H
#define _MODULATE_H

/*==================================
 * Includes
 *==================================*/

#include <stdio.h>
#include <inttypes.h>

/*==================================
 * Macros
 *==================================*/

// Calculated from matlab.
#define FLT_LEN 65

extern const double filterCoef[FLT_LEN];

/*==================================
 * Public
 *==================================*/

 /*
 * Apply the predetermined filter to the data.
 * NOTE This destructively modifies data.
 */
void modulate(double data[], uint32_t dataLen);

#endif // _MODULATE_H