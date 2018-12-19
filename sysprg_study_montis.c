#include "sysprg_study_montis.h"

/*----------------- DINAMIC LISTS UTILS--------------------*/ 
// DYNAMIC STRING
/* Create string*/
String * create_string(){
	String * s = malloc(sizeof(String));
	s->n = 0;
	s->string = malloc(sizeof(char));
	return s;
}
/* destroy_string */
void destroy_string(String * s){
	free(s->string);
	free(s);
	printf("string destroyed\n");
}
/* append to string */
void add_string(String * s, char c){
	s->string = (char*) realloc(s->string, sizeof(char)*((s->n)+2));
	if(s->string == NULL){
		fprintf(stderr, "MEMORY FULL\n");
  		exit(EXIT_FAILURE);
	}
	s->string[s->n] = c;
	s->string[s->n+1] = '\0';
	s->n = (s->n) + 1;
}
/* Print a string */
void print_string(String *s){
	printf("%s\n", s->string);
}
/* merge two strings */
void merge_string(String * s, String * s1){
	for(int i = 0; i < strlen(s1->string); i++)
		add_string(s,s1->string[i]);
}
// STRING LIST
/* Create string list*/
lsts * create_lsts(){
	lsts * new_string_list = malloc(sizeof(lsts));
	new_string_list->n = 0;
	new_string_list->size = 1;
	new_string_list->words = malloc(sizeof(char *));
	return new_string_list;
}
/* Destroy string list */
void destroy_lsts(lsts * lst){
	for(size_t i = 0; i < lst->n; i++){
		free(lst->words[i]);
	}
	free(lst->words);
	free(lst);
	printf("%s\n","lsts deleted" );
}

/* add to string list */
void add_lsts(lsts * lst, const char * word){
	/* If number of elements is too big for actual list, list doubles its size */
	if(lst->n+1 >= lst->size){
		lst->size = (lst->size)*2;
		lst->words = (char**) realloc(lst->words, sizeof(char*)*(lst->size));
		if(lst->words == NULL){
			fprintf(stderr, "MEMORY FULL\n");
      		exit(EXIT_FAILURE);
		}
	}
	/* Allocate memory +1 because \n */
	(lst->words)[lst->n] = (char *) malloc(sizeof(char)*(strlen(word)+1));
	if(lst->words[lst->n] == NULL){
		fprintf(stderr, "MEMORY FULL\n");
  		exit(EXIT_FAILURE);
	}
	memcpy((lst->words)[lst->n],word,strlen(word)+1);
	lst->n = (lst->n) + 1;
}

/* Print the list */
void print_lsts(lsts * lst){
	for(int i = 0 ; i < lst->n ; i++){
		printf("%s\n", (lst->words)[i]);
	}
}

void merge_lsts(lsts * lst, lsts * lst1){
	for(size_t i = 0; i < lst1->n; i++){
		add_lsts(lst, (lst1->words)[i]);
	}
}

// INTEGERS
/* Create int array */
lstn * create_lstn(){
	lstn * new_string_list = malloc(sizeof(lstn));
	new_string_list->n = 0;
	new_string_list->size = 1;
	new_string_list->nums = malloc(sizeof(float*));
	return new_string_list;
}
/* Destroy int list */
void destroy_lstn(lstn * lst){
	free(lst->nums);
	free(lst);
	printf("%s\n","lstn deleted" );
}
/* add to int list */
void add_lstn(lstn * lst, float num){
	/* If number of elements is too big for actual list, list doubles its size */
	if(lst->n >= lst->size){
		lst->size = (lst->size)*2;
		lst->nums = (float*) realloc(lst->nums, sizeof(float*)*(lst->size));
		if(lst->nums == NULL){
			fprintf(stderr, "MEMORY FULL\n");
	  		exit(EXIT_FAILURE);
		}
	}
	lst->nums[lst->n] = num;
	lst->n = (lst->n) + 1;
}
/* Print the list */
void print_lstn(lstn * lst){
	for(size_t i = 0; i < lst->n; i++){
		printf("%f\n", lst->nums[i]);
	}
}

void merge_lstn(lstn * lst, lstn * lst1){
	for(size_t i = 0; i < lst1->n; i++){
		add_lstn(lst, (lst1->nums)[i]);
	}
}

// POINTERS FROM ALREADY ALLOCATED STRINGS

/* add simple strings lists*/
void add_strings_p(strings_p * lst, char * word){

	lst->pointers = (char**) realloc(lst->pointers, sizeof(char*)*(lst->n+1));
	if(lst->pointers == NULL){
		fprintf(stderr, "MEMORY FULL\n");
  		exit(EXIT_FAILURE);
	}

	/* Allocate memory +1 because \n */
	(lst->pointers)[lst->n] = word;
	lst->n = (lst->n) + 1;
}
/* print simple strings lists*/
void print_strings_p(strings_p * lst){
	for(int i = 0; i < lst->n ; i++){
		printf("%s\n", lst->pointers[i]);
	}
}
/* destroy simple strings lists*/
void destroy_strings_p(strings_p * lst){
	free(lst->pointers);
	free(lst);
	printf("string_p eliminated boom headshot\n");
}
/* merge simple strings lists*/
void merge_strings_p(strings_p * lst,strings_p * lst1){
	for(int i = 0; i < lst1->n ; i++){
		add_strings_p(lst, lst1->pointers[i]);
	}
}

// LIST WORKS

/* looks for the  word in words_list, return n_times found, 0 otherwise
  !! substring supported, to remove this feature switch where indicated */
int find_word_in_list(lsts * lst, char * word){
  int check = 0;
  int times = 0;
  for (int i = 0; i < lst->n; i++){
  	/*	switch these if statement */
    if(is_substring((lst -> words)[i], word) == 1){
		times++;
		check = 1;
    }
    // if(strcmp((lst -> words)[i], word) == 0){
    // 	times++;
    //   	check = 1;
    // }
    /* end of switch */
  }
  if (check == 0){
    printf("not found: %s\n", word);
  }
  else{
    printf("%s found %d times\n", word, times);
    return times;
  }
  return 0;
}

/*-------------- FILE UTILS -----------------*/
void print_file(File * f){
	printf("FILENAME: %s\n", f->file_name);
	printf("TEXT IN FILE\n");
	print_string(f->text_file);
	printf("WORDS \n" );
	print_lsts(f->words);
	printf("STRINGS \n" );
	print_lsts(f->strings);
	printf("NUMS \n" );
	print_lstn(f->numbers);
	printf("VALID NUMS \n" );
	print_lstn(f->valid_numbers);
	printf("VALID STRINGS \n" );
	print_lsts(f->valid_strings);
}

void print_input(Input * f){
	printf("TEXT IN INPUT\n");
	print_string(f->text_input);
	printf("WORDS \n" );
	print_lsts(f->words);
	printf("STRINGS \n" );
	print_lsts(f->strings);
	printf("NUMS \n" );
	print_lstn(f->numbers);
	printf("VALID NUMS \n" );
	print_lstn(f->valid_numbers);
	printf("VALID STRINGS \n" );
	print_lsts(f->valid_strings);
}

void destroy_file(File * f){
	destroy_string(f->text_file);
	destroy_lsts(f->words);
	destroy_lsts(f->strings);
	destroy_lstn(f->numbers);
	destroy_lsts(f->valid_strings);
	destroy_lstn(f->valid_numbers);
	printf("file: %s succesfully destroyed\n", f->file_name);
	free(f);
}

void destroy_input(Input * f){
	destroy_string(f->text_input);
	destroy_lsts(f->words);
	destroy_lsts(f->strings);
	destroy_lstn(f->numbers);
	destroy_lsts(f->valid_strings);
	destroy_lstn(f->valid_numbers);
	printf("input succesfully destroyed\n");
	free(f);
}


File * read_file(char * filename){
	/* Create the file, and struct to represent it*/
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp == NULL){
		fprintf(stderr, "FILE NOT FOUND\n");
  		exit(EXIT_FAILURE);
	}
	File * newfile = malloc(sizeof(File));
	/* Name of the file*/ 
	newfile->file_name = filename;
	/* File itself */ 
	newfile->file = fp;

	/* read file char by char */
	char c;
	String * tmp_file_str = create_string();
	while((c = fgetc(fp)) != EOF){
		add_string(tmp_file_str, c);
	}
	newfile->text_file = tmp_file_str;

	newfile->words = word_list(tmp_file_str->string);
	newfile->strings = string_list(tmp_file_str->string);
	newfile->numbers = float_list(tmp_file_str->string);
	newfile->valid_strings = valid_string_list(tmp_file_str->string);
	newfile->valid_numbers = valid_number_list(tmp_file_str->string);

	/* read file line by line*/
	// newfile->text_file = create_string();
	// newfile->words = create_lsts();
	// newfile->strings = create_lsts();
	// newfile->numbers = create_lstn();
	// newfile->valid_strings = create_lsts();
	// newfile->valid_numbers = create_lstn();

	// char buff[MAX_LINE]; 
	// while(fgets(buff, MAX_LINE, fp)){
	// 	for(int i = 0; i < strlen(buff); i++){
	// 		add_string(newfile->text_file, buff[i]);
	// 	}
	// 	lsts *  wo = word_list(buff);
	// 	lsts *  st = string_list(buff);
	// 	lstn *  no = float_list(buff);
	// 	lsts *  vst = valid_string_list(buff);
	// 	lstn *  vno = valid_number_list(buff);

	// 	merge_lsts(newfile->words, wo);
	// 	merge_lsts(newfile->strings, st);
	// 	merge_lstn(newfile->numbers, no);
	// 	merge_lsts(newfile->valid_strings, vst);
	// 	merge_lstn(newfile->valid_numbers, vno);

	// 	free(wo);
	// 	free(st);
	// 	free(no);
	// 	free(vst);
	// 	free(vno);
	// }


	/* FIND EVERYTHING EXCEPT WHITESPACES */
	// char str[MAX_WORD];
	// lsts * lst = create_lsts();
	// while(fscanf(fp, "%s", str) > 0){
	// 	add_lsts(lst, str);
	// }
	// newfile->words = lst;
	fclose(fp);
	return newfile;

}

Input * read_input(){
	/* Create the text, and struct to represent it*/

	Input * newinput = malloc(sizeof(Input));


	/* read file char by char */
	char c;
	String * tmp_file_str = create_string();
	while((c = getchar()) != EOF){
		add_string(tmp_file_str, c);
	}
	newinput->text_input = tmp_file_str;

	newinput->words = word_list(tmp_file_str->string);
	newinput->strings = string_list(tmp_file_str->string);
	newinput->numbers = float_list(tmp_file_str->string);
	newinput->valid_strings = valid_string_list(tmp_file_str->string);
	newinput->valid_numbers = valid_number_list(tmp_file_str->string);

	/* read file line by line*/
	// newinput->text_input = create_string();
	// newinput->words = create_lsts();
	// newinput->strings = create_lsts();
	// newinput->numbers = create_lstn();
	// newinput->valid_strings = create_lsts();
	// newinput->valid_numbers = create_lstn();

	// char buff[MAX_LINE]; 
	// while(gets(buff)){
	// 	for(int i = 0; i < strlen(buff); i++){
	// 		add_string(newinput->text_input, buff[i]);
	// 	}
	// 	lsts *  wo = word_list(buff);
	// 	lsts *  st = string_list(buff);
	// 	lstn *  no = float_list(buff);
	// 	lsts *  vst = valid_string_list(buff);
	// 	lstn *  vno = valid_number_list(buff);

	// 	merge_lsts(newinput->words, wo);
	// 	merge_lsts(newinput->strings, st);
	// 	merge_lstn(newinput->numbers, no);
	// 	merge_lsts(newinput->valid_strings, vst);
	// 	merge_lstn(newinput->valid_numbers, vno);

	// 	free(wo);
	// 	free(st);
	// 	free(no);
	// 	free(vst);
	// 	free(vno);
	// }


	/* FIND EVERYTHING EXCEPT WHITESPACES */
	// char str[MAX_WORD];
	// lsts * lst = create_lsts();
	// while(scanf("%s", str) > 0){
	// 	add_lsts(lst, str);
	// }
	// newinput->words = lst;
	return newinput;
}

/*-------------- TEXT UTILS -----------------*/
/* 	parse words from a string and returns a 
	dynamic list containing them */

lsts * word_list(char* line){
	int check = 0;
	int begin = 0;
	int len = 0;
	lsts * lst = create_lsts();

	for(int i = 0; i < strlen(line); i++){

			/* word begin */
		if((isalpha(line[i]) || isalnum(line[i])) && check == 0){
			check = 1;
			begin = i;
			len++;
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* word continues */
		else if ((isalpha(line[i]) || isalnum(line[i])) && check == 1){
			len++;
				/* word is the last of the given string */
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* Aphostrophe in word */
		else if(ispunct(line[i]) && line[i] == '\'' && check == 1){
			/* Case with '' */
			if(ispunct(line[i+1]) || isspace(line[i+1])){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				i++;
				check=0;
				len = 0;
			}
			/* apostrophe found */
			else{
				len++;
			}
		}
			/* word finished */
		else if((isspace(line[i]) || ispunct(line[i])) && check == 1){
			char * new = malloc(sizeof(char) * (len+1));
			new[len] = '\0';
			memcpy(new, line+begin, len);
			printf("word found: %s\n", new);
			add_lsts(lst, new);
			free(new);
			check=0;
			len = 0;

		}
	}
	return lst;
}

lsts * string_list(char* line){
	int check = 0;
	int begin = 0;
	int len = 0;
	lsts * lst = create_lsts();

	for(int i = 0; i < strlen(line); i++){

			/* word begin */
		if(isalpha(line[i]) && check == 0){
			check = 1;
			begin = i;
			len++;
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* word continues */
		else if (isalpha(line[i]) && check == 1){
			len++;
				/* word is the last of the given string */
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* Aphostrophe in word */
		else if(ispunct(line[i]) && line[i] == '\'' && check == 1){
			/* Case with '' */
			if(ispunct(line[i+1]) || isspace(line[i+1])){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				i++;
				check=0;
				len = 0;
			}
			/* apostrophe found */
			else{
				len++;
			}
		}
			/* word finished */
		else if((isspace(line[i]) || ispunct(line[i]) || isdigit(line[i])) && check == 1){
			char * new = malloc(sizeof(char) * (len+1));
			new[len] = '\0';
			memcpy(new, line+begin, len);
			printf("word found: %s\n", new);
			add_lsts(lst, new);
			free(new);
			check=0;
			len = 0;

		}
	}
	return lst;
}
/*	parse floats from a string and return a 
	dynamic list containing them */

lstn * float_list(char* line){
	int check = 0;
	int begin = 0;
	int len = 0;
	lstn * lst = create_lstn();

	for(int i = 0; i < strlen(line); i++){
			/* num begin */
		if((isdigit(line[i]) || line[i] == '-' || line[i] == '+' ) && check == 0){
			check = 1;
			begin = i;
			len++;
			if(line[i+1] == '-' || line[i+1] == '+'){
				check = 0;
				len = 0;
			}
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				float tmp = atof(new);
				add_lstn(lst, tmp);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* num continues */
		else if (isdigit(line[i]) && check == 1){
			len++;
				/* num is the last of the given string */
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				float tmp = atof(new);
				add_lstn(lst, tmp);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* dot in num */
		else if(ispunct(line[i]) && line[i] == '.' && check == 1){
			/* Case with .. */
			if(ispunct((line[i+1]) || isspace(line[i+1])) && (line[i+1] != '-' || line[i+1] != '+')){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				float tmp = atof(new);
				add_lstn(lst, tmp);
				free(new);
				i++;
				check=0;
				len = 0;
			}
			else if(line[i+1] == '-' || line[i+1] == '+'){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				float tmp = atof(new);
				add_lstn(lst, tmp);
				free(new);
				check=0;
				len = 0;
			}
			/* dot found */
			else{
				len++;
			}
		}
			/* num finished */
		else if((isspace(line[i]) || ispunct(line[i]) || isalpha(line[i])) && check == 1){
			char * new = malloc(sizeof(char) * (len+1));
			new[len] = '\0';
			memcpy(new, line+begin, len);
			if(strlen(new) == 1 && (new[0] == '-' || new[0] == '+')){
				check = 0;
				len = 0;
			}
			else{
			printf("word found: %s\n", new);
				float tmp = atof(new);
				add_lstn(lst, tmp);
			}
			free(new);
			check=0;
			len = 0;

		}
	}
	return lst;
}

/* split a string with spaces */
lsts * all_list(char * line){
	int check = 0;
	int begin = 0;
	int len = 0;
	lsts * lst = create_lsts();
	for(int i=0; i < strlen(line); i++){
		if(isspace(line[i])  < 1 && check == 0){
				check = 1;
				begin = i;
				len++;
				if(i == strlen(line)-1){
					char * new = malloc(sizeof(char) * (len+1));
					new[len] = '\0';
					memcpy(new, line+begin, len);
					printf("word found: %s\n", new);
					add_lsts(lst, new);
					free(new);
					check=0;
					len = 0;
				}
		}		
			/* word continues */
		else if(isspace(line[i]) < 1 && check == 1){
			len++;
				/* word is the last of the given string */
			if(i == strlen(line)-1){
				char * new = malloc(sizeof(char) * (len+1));
				new[len] = '\0';
				memcpy(new, line+begin, len);
				printf("word found: %s\n", new);
				add_lsts(lst, new);
				free(new);
				check=0;
				len = 0;
			}
		}
			/* word finished */
		else if(isspace(line[i]) && check == 1){
			char * new = malloc(sizeof(char) * (len+1));
			new[len] = '\0';
			memcpy(new, line+begin, len);
			printf("word found: %s\n", new);
			add_lsts(lst, new);
			free(new);
			check=0;
			len = 0;
		}
	}
	return lst;
}
/* 	parse valid words from a string
	and return a dynamic list of pointers
	to the words */
strings_p * strings_p_list(char * line){
	int begin = 0;
	int check = 0;
	int len = strlen(line);

	strings_p * lst= malloc(sizeof(strings_p));
	lst->text = line;
	lst->n = 0;
	lst->pointers = malloc(sizeof(char**));

	for(int i = 0; i < len; i++){
		if(check == 0 && isalpha(line[i])){
			begin = i;
			check = 1;
		}
		else if(check == 1 && (isspace(line[i]) || i == len-1)){
			check = 0;
			if(i != len-1){
				line[i] = '\0';
			}
			if(is_valid_string(line+begin)){
				add_strings_p(lst, line+begin);
			}
		}
	}
	return lst;
}

/*	parse valid words from a given string 
	return dynamic words list */
lsts * valid_string_list(char* line){
	lsts * tmp = all_list(line);
	lsts * lst = create_lsts();
	for(int i = 0; i < tmp->n; i++){
		if(is_valid_string(tmp->words[i]))
			add_lsts(lst, tmp->words[i]);
	}
	destroy_lsts(tmp);
	return lst;
}
/*	parse valid numbers from a given string 
	return dynamic float list */
lstn * valid_number_list(char* line){
	lsts * tmp = all_list(line);
	lstn * lst = create_lstn();
	for(int i = 0; i < tmp->n; i++){
		if(is_valid_number(tmp->words[i]))
			add_lstn(lst, atof(tmp->words[i]));
	}
	destroy_lsts(tmp);
	return lst;
}

/*	determine if given string is a word
	returns 1, 0 otherwise. recognises
	words like "mama's" or "mama", to
	remove accent comment where indicated */

int is_valid_string(char * c){
	int check = 0;
	for(int i = 0; i < strlen(c); i++){
		if(isalpha(c[i])){
			continue;
		}
		/* comment this if statement for
		words without accent */
		else if(c[i] == '\''){
			if(check == 1)
				return 0;
			if(i == strlen(c)-1)
				return 0;
			check = 1;
		}
		else if(c[i] != '\'' && ispunct(c[i])){
			return 0;
		}
		else
			return 0;
	}
	return 1;
}
/*	determine if given string is a float
	returns 1, 0 otherwise. recognises
	nums like "-1.123" or "2", for ints
	comment where indicated */
int is_valid_number(char * c){
	if(strcmp(c, "+") == 0 || strcmp(c, "-") == 0){
		return 0;
	}
	int check = 0;
	for(int i = 0; i < strlen(c); i++){
		if(i == 0 && (c[i] == '+' || c[i] == '-')){
			continue;
			if(strlen(c) == 1)
				return 0;
		}
		else if(isdigit(c[i]))
			continue;
		/* comment this if statement for
		only ints */
		else if(c[i] == '.'){
			if(check == 1)
				return 0;
			if(i == strlen(c)-1)
				return 0;
			check = 1;
		}
		else
			return 0;
	}
	return 1;
}

/* 	look if parameter substring, is a substring of 
	parameter string */
int is_substring(char * string, char * substring){
	size_t len = strlen(string);
	size_t len1= strlen(substring);
	if(len1 > len)
		return 0;
	if(strcmp(string, substring) == 0)
		return 1;
	for(int i = 0; i < len - len1 + 1; i++){
		if(strncmp(string+i, substring, strlen(substring)) == 0)
			return 1;
	}
	return 0;
}

// INDEXES UTILS


/* return every position where the word searched is found
   the indexes are stored into a number_list */
lstn * find_index_word(char * string, char * word){
  lstn * indexes = create_lstn();

  int check = 0;
  int times = 0;
  for (int i = 0; i < strlen(string); i++){
    if(strncmp(string+i,word, strlen(word)) == 0){
      add_lstn(indexes, i);
      times++;
      check = 1;
    }
  }
  if (check == 0){
    printf("not found: %s\n", word);
  }
  else{
    printf("%s, found - times: %d\n", word, times);
    return indexes;
  }
  return indexes;
}



/* return parts of text separated by delimeter
   the delimeters can be a string */
void split_between_delimeter(char * string, char * delimeter){
  lstn *  del_indexes = find_index_word(string, delimeter);
  int begin = 0;
  int index;
  int upto;
  size_t len = strlen(delimeter);

  for(int i = 0; i < del_indexes->n -1; i++){
    index = (int)(del_indexes->nums)[i]+len;
    upto = (int)(del_indexes->nums)[i+1] - 1;
    // printf("-> %d to %d\n", index, upto );
    char * toprint = malloc(sizeof(char) * (upto-index + 2));
    toprint[upto-index+1] = '\0';
    memcpy(toprint, string+index, upto-index+1);
    printf("%s\n", toprint);
    free(toprint);
  }
  destroy_lstn(del_indexes);
}

/*	split the string using delimeter */
void split_delimeter(char * string, char * delimeter){
  lstn *  del_indexes = find_index_word(string, delimeter);
  size_t d_len = strlen(delimeter);
  for(int i = 0; i < del_indexes->n; i++){
    if(i == 0){
      int index = (int)(del_indexes->nums)[i];
      char * toprint = malloc(sizeof(char) * index);
      toprint[index] = '\0';
      memcpy(toprint, string, index);
      printf("%s\n", toprint);
      free(toprint);
    }

    else {
      int index = (int)(del_indexes->nums)[i-1] + d_len;
      int upto = (int)(del_indexes->nums)[i];
      // printf("-> %d to %d\n", index, upto );

      char * toprint = malloc(sizeof(char) * (upto-index + 1));
      toprint[upto-index] = '\0';
      memcpy(toprint, string+index, upto-index);
      printf("%s\n", toprint);
      free(toprint);

      if (i == ((del_indexes -> n) - 1)){
        printf("%s\n", string+upto+d_len);
      }
    }
  }
}