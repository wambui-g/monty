#include "monty.h"

/**
 * swap - adds top two elements of a stack
 * @stack: stack head
 * @line_number: line number
 *
 * Return: no return
 */

void swap(stack_t **stack, unsigned int line_number)
{
	if (is_stack_empty(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
