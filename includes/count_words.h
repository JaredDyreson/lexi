#include <stdio.h>

typedef struct sentence_t {
  char* content;
  size_t words;
  char** word_map;
} sentence_t;

size_t count(char*);
char** map_words(char*);
