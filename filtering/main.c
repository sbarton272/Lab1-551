/**
 * Main
 */

/*==================================
 * Includes
 *==================================*/

#include "main.h"

 /*==================================
 * Constants
 *==================================*/

/*==================================
 * Public
 *==================================*/

int main(int argc, char *argv[]) {

  audio_t* audio = malloc(sizeof(audio_t));
  readDatFile(AUDIO_FLT_FILE, audio);
  freeAudio(audio);
  printf("Saved to %s\n", AUDIO_FLT_FILE);
  
  printf("Saved to %s\n", AUDIO_MOD_FILE);

}

/*==================================
 * Private
 *==================================*/

// 32 bit float, little-endian
void readDatFile(char* filename, audio_t* data) {

  // Read in and parse data
  FILE* dataFp = fopen(filename, "r");

  // Error check
  if (dataFp == NULL) {
    printf("Please provide valid data file name\n");
    exit(EXIT_FAILURE);
  }

  // Allocate audio file and buffer space
  audio->data = malloc(DATA_SIZE*sizeof(float));

  // Read as floats
  audio->len = fread((void *)audio->data, sizeof(float), DATA_SIZE, dataFp);

  // Close file
  fclose(dataFp);
}

void writeDatFile(char* filename, float[] data, uint32_t dataLen);

void freeAudio(audio_t* audio) {
  free(&audio.data);
  free(audio);
}

