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
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		value = atoi(arg);
		push(stack, line_number, value);
	}
	else if (opcode && strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (opcode && strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (opcode && strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (opcode && strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (opcode && strcmp(opcode, "nop") == 0)
		add(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
