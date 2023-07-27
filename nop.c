#include "monty.h"

/**
 * nop - nothing
 * @stack: stack head
 * @line_number: line number
 *
 * Return: no return
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /*avoid unused variable warning*/
	(void)line_number; /*avoid unused varaible warning*/
	/*THe nop opcode does not do anything*/
}
