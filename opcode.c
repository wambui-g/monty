#include "monty.h"

/**
 * handle_opcode- handle opcodes
 * @opcode: opcode to consider
 * @arg: arguement
 * @stack: stack
 * @line_number: line number with opcodes
 *
 * Return: void
 */
void handle_opcode(char *opcode, char *arg,
		stack_t **stack, unsigned int line_number)
{
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_int(arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		value = atoi(arg);
		push(stack, line_number, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
