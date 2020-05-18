#include "../includes/sentence_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

/*
 * constructor for sentence_t
 * goal: assign a pointer to a pointer of a dynamic char array and count the words
 * cavaet: do not free sentence_t->content, it will cause a double_free error when
 * the original block it is pointing to is freed
*/

sentence_t* sentence_constructor(char* line){
  sentence_t* s = (sentence_t*)malloc(sizeof(sentence_t));
  s->content = line;
  s->word_count = count(s->content);
  return s;
}

/*
 * destructor for sentence_t
 * goal: free sentence_t object
 * cavaet: NONE
*/

void sentence_destructor(sentence_t* s){ free(s); }

/*
 * Garbage collector for multiple strings
 * goal: remove multiple strings in one line
 * cavaet: can be called again which results in double_free
 */
void string_garbage_collector(int count, ...){
  va_list arguments;
  va_start(arguments, count);
  for(int i = 0; i < count; ++i){ free(va_arg(arguments, char*)); }
}


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

void change_case_asserts(){
  printf("Calling %s\n", __func__);
  char* string = (char*)malloc(BUFSIZ * sizeof(char));
  sprintf(string, "Hello World");

  char* to_upper_version = change_case(string, toupper, islower);
  char* to_lower_version = change_case(string, tolower, isupper);

  assert(strcmp(to_upper_version, "HELLO WORLD") == 0);
  assert(strcmp(to_lower_version, "hello world") == 0);

  printf("All assertions passed for %s\n", __func__);
  string_garbage_collector(3, string, to_lower_version, to_upper_version);
}

void word_count_assert_tests(){
  printf("Calling %s\n", __func__);
  char* regular_string = (char*)malloc(BUFSIZ * sizeof(char));
  char* buffered_string = (char*)malloc(BUFSIZ * sizeof(char));

  sprintf(regular_string, "Hello World");
  sprintf(buffered_string, "           Hello World");
  
  assert(count(regular_string) == 2);
  assert(count(buffered_string) == 2);
  string_garbage_collector(2, regular_string, buffered_string);

  printf("All assertions passed for %s\n", __func__);
}

void sentence_t_asserts(){
  word_count_assert_tests();
  change_case_asserts();
}
