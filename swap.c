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
	int temp = (*stack)->n;

	if (is_stack_empty(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
