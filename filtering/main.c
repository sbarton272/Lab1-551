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

  // Load audio
  audio_t* audio = malloc(sizeof(audio_t));
  readDatFile(AUDIO_IN_FILE, audio);
  printf("Read in (%d) floats\n", audio->len);

  // Filter audio, Note destructive
  filter(audio->data, audio->len);
  writeDatFile(AUDIO_FLT_FILE, audio);
  printf("Saved to %s\n", AUDIO_FLT_FILE);

  printf("Saved to %s\n", AUDIO_MOD_FILE);

  freeAudio(audio);

}

/*==================================
 * Private
 *==================================*/

// 32 bit double, little-endian
void readDatFile(const char* filename, audio_t* audio) {

  FILE* dataFp = safeFileOpen(filename, "r");

  // Allocate audio file and buffer space
  audio->data = malloc(DATA_SIZE*sizeof(double));

  // Read as doubles
  audio->len = fread((void *)audio->data, sizeof(double), DATA_SIZE, dataFp);

  fclose(dataFp);
}

void writeDatFile(const char* filename, audio_t* audio) {

  FILE* dataFp = safeFileOpen(filename, "w");

  size_t writenBytes = fwrite((void *)audio->data, sizeof(double), audio->len, dataFp);

  fclose(dataFp);

}

FILE* safeFileOpen(const char* filename, char* mode) {
  
  FILE* dataFp = fopen(filename, mode);

  // Error check
  if (dataFp == NULL) {
    printf("Please provide valid data file name\n");
    exit(EXIT_FAILURE);
  }

  return dataFp;
}

void freeAudio(audio_t* audio) {
  free(audio->data);
  free(audio);
}

