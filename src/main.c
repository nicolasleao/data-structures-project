/*
Minimal huffman compression program
Written by:
Nicolas Leão, Matheus Artur, Luis Cabus and Fábio Vinícius.
UFAL
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Function to compress a file.
void compress(FILE* file) {
	char *current_byte = malloc(sizeof(char *));
	fnode_l *frequency_list = NULL;
	// fread will read one byte at a time from the "file" variable and store it in the "current_byte" variable.
	while(fread(current_byte, 1, 1, file)) {
		/* Another variable (byte_to_add) that recieves the same value as current_byte is necessary, since the value of current_byte will 
		change in every iteration */
		char* byte_to_add = malloc(sizeof(char *));
		*byte_to_add = *current_byte;
		add_freq(&frequency_list, (void *)byte_to_add);
	}

	// Debug loop to print the bytes in hexadecimal and their frequencies.
	while(frequency_list != NULL) {
		printf("BYTE: %hhx / FREQ: %d\n", *((char *)frequency_list->value), frequency_list->freq);
		frequency_list = frequency_list->next;
	}
	puts("");
}

void main(int argc, char **argv) {
	/* The command that will determine the operation to be executed is passed as the first argument (argv[1]).
	the available command/operation touples are: (-c, compress) and (-e, extract). 
	The file that will be used is passed as the second argument (argv[2]) when the program is executed. */
	
	// An example of the usage is: ./huffman -c picture.jpg, that will compress the file "picture.jpg"

	/* The file specified will be stored in the variable "file", as read-only to ensure that the original data is not
	altered in the compression process. */
	FILE *file = fopen(argv[2], "r");
	if(file == NULL) {
		// If the file cannot be accessed, the program exits with error code 1.
		printf("Error! File could not be loaded successfully.\nExiting...\n");
		exit(1);
	}

	if(strcmp(argv[1], "-c") == 0) {
		compress(file);
	} 
	else if(strcmp(argv[1], "-e") == 0) {
		char *current_byte = malloc(sizeof(char *));
		//fread will read one byte at a time from the "file" variable and store it in the "current_byte" variable.
		while(fread(current_byte, 1, 1, file)) {
			//TODO: extraction algorithm.
			//magic happens here.
		}
	}
	fclose(file);
	exit(0);
}
