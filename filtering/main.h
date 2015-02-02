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
#include <inttypes.h>

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
	float[] data;
	uint32_t len;
} audio_t;

/*==================================
 * Public
 *==================================*/

int main(int argc, char *argv[]);

/*==================================
 * Private
 *==================================*/

static audio_t* readDatFile(char* filename);

static void writeDatFile(char* filename, float[] data, uint32_t dataLen);

static void freeAudio(audio_t* audio);

#endif // _MAIN_H