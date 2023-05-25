#include "monty.h"
/* header */

/**
* _pall - prints the values on the stack, starting from top
*
* @stack: double pointer to the head of list
*
* @line_number: number of line
*
* Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_stack;

	(void) line_number;

	current_stack = *stack;

	while (current_stack != NULL)
	{
		fprintf(stdout, "%d\n", current_stack->n);
		current_stack = current_stack->next;
	}
}
