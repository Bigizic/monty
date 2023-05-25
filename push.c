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
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{fprintf(stderr, "Error: malloc failed");
		_free_stack(stack);
		exit(EXIT_FAILURE); }
	if (data == NULL || isspace(data[0]) != 0)
	{fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		_free_stack(stack);
		exit(EXIT_FAILURE); }
	for (i = 0; data[i] != '\0'; i++)
	{
		if (!isdigit(data[i]))
		{
			fprintf(stderr, "L%d: usage: push integer2\n", line_number);
			free(new_node);
			_free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	i = atoi(data);
	new_node->n = i;
	if (*stack == NULL)
	{
		*stack = new_node;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = (*stack);
		(*stack) = new_node;
		new_node->prev = NULL;
	}
}
