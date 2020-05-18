#include "includes/count_words.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>


char* change_case(char* line, int (*mutator)(char), int (*comparator)(char)) {
  int i = 0;
  char* mutated = (char*)malloc((int)strlen(line)*sizeof(char));
  while(*line != '\0'){
    if(comparator(*line) && !isspace(*line)){
      mutated[i++] = mutator(*line++);
    } else {
      mutated[i++] = *line++;
    }
  }
  mutated[i++] = '\0';
  return mutated;
}

void string_garbage_collector(int count, ...){
  va_list arguments;
  va_start(arguments, count);
  for(int i = 0; i < count; ++i){ free(va_arg(arguments, char*)); }
}

void change_case_asserts(){
  char* string = (char*)malloc(BUFSIZ * sizeof(char));
  sprintf(string, "Hello World");

  char* to_upper_version = change_case(string, toupper, islower);
  char* to_lower_version = change_case(string, tolower, isupper);

  assert(strcmp(to_upper_version, "HELLO WORLD") == 0);
  assert(strcmp(to_lower_version, "hello world") == 0);

  printf("All assertions passed!\n");
  string_garbage_collector(3, string, to_lower_version, to_upper_version);
}

void word_count_assert_tests(){
  char* regular_string = (char*)malloc(BUFSIZ * sizeof(char));
  char* buffered_string = (char*)malloc(BUFSIZ * sizeof(char));

  sprintf(regular_string, "Hello World");
  sprintf(buffered_string, "           Hello World");
  
  assert(count(regular_string) == 2);
  assert(count(buffered_string) == 2);
  string_garbage_collector(2, regular_string, buffered_string);

  printf("Finished %s\n", __func__);
}

int main(int argc, const char* argv[]){
  /*change_case_asserts();*/
  word_count_assert_tests();
  return 0;
}
