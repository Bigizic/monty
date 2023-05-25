#include "monty.h"
/* header */

/**
* free_stack - frees stack list
*
* @stack: list to be freed
*
* Return: void
*/
void free_stack(stack_t *stack)
{
	stack_t *current_stack;

	while (current_stack != NULL)
	{
		current_stack = stack->next;
		free(stack);
		stack = current_stack;
	}
}
