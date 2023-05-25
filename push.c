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
	stack_t *new_node = malloc(sizeof(stack_t));
	long int value;
	char *endptr;

	if (new_node == NULL)
	{fprintf(stderr, "Error: malloc failed");
		_free_stack(stack);
		exit(EXIT_FAILURE); }
	if (data == NULL || isspace(data[0]) != 0)
	{fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		_free_stack(stack);
		exit(EXIT_FAILURE); }
	value = strtol(data, &endptr, 10);
		if (!isdigit(value))
		{
			fprintf(stderr, "L%d: usage: push integer2: %ld\n", line_number, value);
			free(new_node);
			_free_stack(stack);
			exit(EXIT_FAILURE);
		}
	new_node->n = (int)value;
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
