#include "monty.h"

/**
 * sub- subtracts top from second
 * @stack: pointer to stack array
 * @line_number: line number of opcode
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (is_stack_empty(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;

	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
