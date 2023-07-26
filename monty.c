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
	int value;
	/*size_t len = 0;*/
	stack_t *stack = NULL;

	check_arguements(argc);
	file = open_file(argv[1]);
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");
		if (opcode && strcmp(opcode, "push") == 0)
		{
			if (!arg || !is_int(arg))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit_helper(file, &stack);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, line_number, value);
		}
		else if (opcode && strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else if (opcode && strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit_helper(file, &stack);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	exit_helper(file, &stack);
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

/**
 * exit_helper- helper
 * @file: file
 * @stack: stack
 *
 * Return: void
 */
void exit_helper(FILE *file, stack_t **stack)
{
	fclose(file);
	free_stack(stack);
}
