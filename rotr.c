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
	stack_t *current, *last_stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last_stack = *stack;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;

	current = *stack;
	*stack = last_stack;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = current;
	current->prev = *stack;
}
