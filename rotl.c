#include "monty.h"
/* header */

/**
* _rotl - rotate the stack to the top, rotl never fails
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *rotate_node;

	if (*satck == NULL || (*stack)->next == NULL)
		return;

	rotate_node = (*stack)->next;
	rotate_node->prev = NULL;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = rotate_node;
	(*stack) = rotate_node;
}
