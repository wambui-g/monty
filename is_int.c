#include "monty.h"

/**
 * is_int- checks if integer
 * @str: user input
 *
 * Return: 1 if int or 0 otherwise
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
