#include "monty.h"

/**
* _push - pushes an element to the stack
*
* @stack: head list
*
* @line_number: unsigned int type
*
* Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *push = malloc(sizeof(stack_t));

	if (push == NULL)
	{fprintf(stderr, "Error: malloc failed");
		_free_stack(stack);
		exit(EXIT_FAILURE); }
	if (data == NULL || isspace(data[0]) != 0)
	{fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(push);
		_free_stack(stack);
		exit(EXIT_FAILURE); }
	for (i = 0; data[i] != '\0'; i++)
	{
		if (isdigit(data[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(push);
			_free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	i = atoi(data);
	push->n = i;
	if (*stack == NULL)
	{
		*stack = push;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		(*stack)->prev = push;
		push->next = (*stack);
		(*stack) = push;
		push->prev = NULL;
	}
}
