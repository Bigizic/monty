#include "monty.h"

/**
* _pop - removes the top element of the stack
*
* @stack: head of list
*
* @line_number: unsigned int type
*
* Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev;
	
	if (*stack != NULL)
	{
		prev = (*stack);
		*stack = (*stack)->next;
		free(prev);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

