#include "monty.h"
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

/**
 * main- entry point
 * @argc: number of arguements
 * @argv: arguements
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	char *opcode;
	char *arg;
	unsigned int line_number = 1;
	/*int value;*/
	/*size_t len = 0;*/
	stack_t *stack = NULL;

	check_arguements(argc);
	file = open_file(argv[1]);
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		handle_opcode(opcode, arg, &stack, line_number);

		line_number++;
	}
	fclose(file);
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}

/**
 * check_arguements- helper function
 * @argc: arguements
 *
 * Return: void
 */
void check_arguements(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_file- helper function
 * @file_path: as is
 *
 * Return: file
 */
FILE *open_file(const char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * free_stack- frees stack
 * @stack: stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
