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

	if (*stack != NULL)
	{
		while (stack->prev != NULL)
			stack = stack->prev;
		while (stack != NULL)
		{
			current_stack = stack->next;;
			free(stack);
			stack = current_stack;
		}
	}
}
