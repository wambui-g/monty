#include "monty.h"

/**
 * pint - pint opcode
 * @stack: as is
 * @line_number: as is
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (is_stack_empty(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
