#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representationof a stack or queue
 * @n: integer
 * @prev: previous element
 * @next: next element
 *
 * Description: doubly lineked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle opcode
 *
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
