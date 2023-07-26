#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

stack_t *stack = NULL;

/**
 * is_int- checks if input is integer
 * @str: user input
 *
 * Return: 1 if int, 0 otherwise
 */
int is_int(const char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
