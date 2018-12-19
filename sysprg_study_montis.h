/* 
Author: Sonny Monti Date: 22 August.
This header and the relative c file have been made, in order to improve my programming tecnique.
It has been made during August with Umberto Sani.

DESCRIPTION:

	-Various ways to read textual input, or FILE input
	-Dynamic lists

*/

#ifndef STUDY_H
#define STUDY_H

#define MAX_LINE 10000
#define MAX_WORD 100


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>	


/*----------------- STRUCTS --------------------*/ 
/* pointers to words in a string */
typedef struct simple_words{
	char * text;
	size_t n;
	char ** pointers;
} strings_p;


/* Dynamic String */
typedef struct dynamic_string{
	size_t n;
	char * string;
} String;

/* Struct for dynamic list of nums*/
typedef struct list_nums{
	size_t n;
	size_t size;
	float* nums; 
} lstn;

/* Struct for dynamic list of chars*/
typedef struct list_string{
	size_t n;
	size_t size;
	char** words; 
} lsts;

/* Struct that represent files */
typedef struct file_struct {
	/* File object */
	FILE * file;
	/* File Name*/
	char * file_name;
	/* list of file words */
	lsts * words;
	/* list of file strings */
	lsts * strings;
	/* list of file numbers */
	lstn * numbers;
	/* list of file valid strings */
	lsts * valid_strings;
	/* list of file valid numbers */
	lstn * valid_numbers;
	/* text contained in the file */
	String * text_file;
} File;

/* Struct that represent textual input */
typedef struct text_struct {
	/* list of file words */
	lsts * words;
	/* list of file strings */
	lsts * strings;
	/* list of file numbers */
	lstn * numbers;
	/* list of file valid strings */
	lsts * valid_strings;
	/* list of file valid numbers */
	lstn * valid_numbers;
	/* text contained in the file */
	String * text_input;
} Input;


/*----------------- DINAMIC LISTS UTILS--------------------*/ 

// LIST GENERATORS DESTROYERS ADDERS AND PRINTERS

// STRING

/* Create string*/
String * create_string();
/* destroy_string */
void destroy_string(String * s);
/* append to string */
void add_string(String * s, char c);
/* Print a string */
void print_string(String *s);
/* merge two strings */
void merge_string(String * s, String * s1);

// STRINGS

/* Create string list*/
lsts * create_lsts();
/* Destroy string list */
void destroy_lsts(lsts * lst);
/* add to string list */
void add_lsts(lsts * lst,const  char * word);
/* Print the list */
void print_lsts(lsts * lst);

void merge_lsts(lsts * lst, lsts * lst1);

// FLOATS

lstn * create_lstn();
/* Destroy string list */
void destroy_lstn(lstn * lst);
/* add to stringlstn list */
void add_lstn(lstn * lst, float  num);
/* Print the list */
void print_lstn(lstn * lst);

void merge_lstn(lstn * lst, lstn * lst1);

// POINTERS FROM ALREADY ALLOCATED STRINGS

/* list of pointers */
void add_strings_p(strings_p * lst, char * word);
/* 	return a struct containing a string and a list of pointers to 
	its words */
strings_p * strings_p_list(char * line);
/* print it */
void print_strings_p(strings_p * lst);
/* destroy simple strings list */
void destroy_strings_p(strings_p * lst);
/* merge simple strings lists*/
void merge_strings_p(strings_p * lst,strings_p * lst1);

// LIST WORKS 

/* looks for the  word in words_list, return n_times found
	, 0 otherwise !! substring supported */
int find_word_in_list(lsts * lst, char * word);

/*----------------- READ INPUT --------------------*/ 

// FILES
/* Creates a file struct, from a filename*/ 
File * read_file(char * filename);
/* print all lists within a file */
void print_file(File * f);
/* destroy a file */
void destroy_file(File * f);

// STANDARD INPUT
/* Creates a input struct*/ 
Input * read_input();
/* print all lists within a input */
void print_input(Input * f);
/* destroy a input */
void destroy_input(Input * f);



/*---------------- STRING-CHAR UTILS---------------------*/ 

// LIST CREATORS FROM STRINGS

/* return a list with all */
lsts * all_list(char * line);
/* Return a list of char* containing alphanum and 
aphostrophe words from a string, uses white-space as delimeter*/
lsts * word_list(char* line);
/* Return a list of char* from a string, uses white-space and numbers as delimeter*/
lsts * string_list(char* line);
/* Return a list of floats from a string, uses white-space and characters as delimeter*/
lstn * float_list(char* line);
/* Return a list of char* that are valid in line*/
lsts * valid_string_list(char* line);
/* Return a list of float that are valid in line*/
lstn * valid_number_list(char* line);
/* return a list of pointers to words in the line */
strings_p * word_p_list(char * line);


// STRING CHECKS

/*	determine if given string is a word
	returns 1, 0 otherwise. recognises
	words like "mama's" or "mama", to
	remove accent comment where indicated */
int is_valid_string(char * c);
/*	determine if given string is a float
	returns 1, 0 otherwise. recognises
	nums like "-1.123" or "2", for ints
	comment where indicated */
int is_valid_number(char *c);

/* 	look if parameter substring, is a substring of 
	parameter string */
int is_substring(char * string, char * substring);



// INDEXES UTILS
/*	return a list of floats representing the indexes where
	word is substring in string
	REMEMBER to cast the list to ints */
lstn * find_index_word(char * string, char * word);
/* return parts of text separated by delimeter
   the delimeters can be a string */
void split_between_delimeter(char * string, char * delimeter);
/*	split the string using delimeter */
void split_delimeter(char * string, char * delimeter);



#endif