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
#define MODULATE_FLT_LEN 100
#define MODULATE_FREQ_MOD 11025
#define MODULATE_FREQ_SMP 44100

/*==================================
 * Public
 *==================================*/

 /*
 * Apply the predetermined filter to the data.
 * NOTE This destructively modifies data.
 */
void modulate(double data[], uint32_t dataLen);

#endif // _MODULATE_H