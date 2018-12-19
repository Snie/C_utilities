#include "word_reader.h"

const char * read_next_word(FILE * file){
  char * word = malloc(sizeof(char *) * WORD_MAX_LEN);
  char c;
  int len = 0;
  while(isalpha(c = fgetc(file)) > 0){
    // printf("%c\n", c);
    word[len] = c;
    len++;
  }
  if(len == 0){
    return NULL;
  }

  word[len] = '\0';
  // printf("%s\n", word);
  return word;
}


int main(int argc, char const *argv[]) {
  /* code */
  FILE * fp;
  fp = fopen("file.txt", "r");
  if (ferror((FILE*)fp)) {
    fprintf(stderr,"Oops, error reading file\n");
    abort();
  }

  for(int i = 0; i < 18; i++) {
    printf("%s\n", read_next_word(fp));
  }




  fclose(fp);
  return 0;
}
