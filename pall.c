#include "monty.h"

/**
 * pall- opcode for pall
 * @stack: pointer to stack array
 * @line_number: as is
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
