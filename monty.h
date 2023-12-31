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


/**
 * is_int- checks if input is integer
 * @str: user input
 *
 * Return: 1 if int, 0 otherwise
 */
int is_int(const char *str);
void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void check_arguements(int argc);
FILE *open_file(const char *file_path);
void free_stack(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
int is_stack_empty(stack_t *stack);
void handle_opcode(char *opcode, char *arg, stack_t **stack,
	unsigned int line_number);
void exit_helper(FILE *file, stack_t **stack);

#endif /* MONTY_H */
