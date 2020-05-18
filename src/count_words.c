#include "../includes/count_words.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

size_t count(char* line){
  while(isspace(*line++)){}

  size_t count = 0;
  char* mutate = strdup(line);
  char* token = strtok(mutate, " ");
  while(mutate){
    count++;
    mutate = strtok(NULL, " ");
  }
  return count;
}

/*char** map_words(char* line){*/
  /*size_t amount = count(line);*/
  /*char** word_map = (char*)malloc((int)amount*sizeof(char*));*/

  /*int start = 0, end = 0;*/
  /*char* mutate = strdup(line);*/

  /*while(muate){*/
    
  /*}*/

  /*return word_map;*/
/*}*/
