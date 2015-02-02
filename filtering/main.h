/**
 * Main:
 * - Filter audio
 * - Modulate audio
 */

#ifndef _MAIN_H
#define _MAIN_H

/*==================================
 * Includes
 *==================================*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "filter.h"
#include "modulate.h"

/*==================================
 * Macros
 *==================================*/

const char *AUDIO_IN_FILE = "hw1_noisy.dat";
const char *AUDIO_FLT_FILE = "hw1_filtered.dat";
const char *AUDIO_MOD_FILE = "hw1_modulated.dat";

#define DATA_SIZE (262144)

/*==================================
 * Structs
 *==================================*/

typedef struct
{
	double* data;
	uint32_t len;
} audio_t;

/*==================================
 * Public
 *==================================*/

int main(int argc, char *argv[]);

/*==================================
 * Private
 *==================================*/

static void readDatFile(const char* filename, audio_t* audio);

static void writeDatFile(const char* filename, audio_t* audio);

static FILE* safeFileOpen(const char* filename, char* mode);

static void freeAudio(audio_t* audio);

#endif // _MAIN_H