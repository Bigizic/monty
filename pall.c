#include "monty.h"

/**
* _pall - prints stack n
*
* @stack: pointer to head
*
* @line_number: line number for error
*
* Return: void
*/
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
