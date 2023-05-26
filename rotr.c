#include "monty.h"
/* header */

/**
* _rotr - rotate the stack to the bottom rotr never fails
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (current->next)
		current = current->next;
	current->next = *stack;
	current->prev->next = NULL;
	current->prev = NULL;
	(*stack)->prev = current;
	*stack = current;
}
