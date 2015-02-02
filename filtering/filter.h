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
#define FILTER_FLT_LEN 65

/*==================================
 * Public
 *==================================*/

 /*
 * Apply the predetermined filter to the data.
 * NOTE This destructively modifies data.
 */
void filter(double data[], uint32_t dataLen);

#endif // _FILTER_H