#include "monty.h"

/**
 * pop - prints the top
 * @stack: stack head
 * @line_number: line number
 *
 * Return: no return
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (is_stack_empty(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
