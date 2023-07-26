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
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	char *arg = strtok(line, " \t\n");
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
