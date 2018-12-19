#ifndef WORD_READER_INCLUDED
#define WORD_READER_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define WORD_MAX_LEN 1024

extern const char * read_next_word(FILE *);

#endif
