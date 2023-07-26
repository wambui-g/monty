#include "monty.h"
#include <stdio.h>

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
	char *line = NULL, *opcode, *arg = strtok(line, " \t\n");
	unsigned int line_number = 1, read, value;
	size_t len = 0;

	check_arguements(argc);
	file = open_file(argv[1]);
	while ((read == getline(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \t\n");
		if (opcode && strcmp(opcode, "push") == 0)
		{
			if (!arg || !is_int(arg))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, line_number, value);
		}
		else if (opcode && strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	fclose(file);
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
