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

  // Read in and parse data
  FILE* dataFp = fopen(AUDIO_IN_FILE, "r");

  // Error check
  if (dataFp == NULL) {
    printf("Please provide valid data file name\n");
    exit(EXIT_FAILURE);
  }

  printf("Saved to %s\n", AUDIO_FLT_FILE);
  printf("Saved to %s\n", AUDIO_MOD_FILE);

}