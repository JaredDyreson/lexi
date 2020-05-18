#pragma once
#include <stdio.h>

typedef struct sentence_t {
  char* content;
  //word_t** word_map;
  size_t word_count;
} sentence_t;

// constructors and destructors
//

sentence_t* sentence_constructor(char*);
void sentence_destructor(sentence_t*);
void string_garbage_collector(int, ...);

// attributes
size_t count(char*);


// member functions
char* change_case(char*, int(*)(char), int(*)(char));
char** map_words(char*);

// tests

void sentence_t_asserts();
void change_case_asserts();
void word_count_assert_tests();
