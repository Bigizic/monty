#include "monty.h"
/* header */

/**
* _push - pushes an element to the stack
*
* @stack: double pointer to the list
*
* @line_number: instruction appears
*
* Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	char argument[128] = "";
	int i;

	if (argument == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < strlen(argument); i++)
	{
		if (!isidgit(argument[i]) && argument[0] != '-')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	add_node(stack, atoi(argument));
}

/**
* add_node - add the data to be pushed
*
* @stack: double pointer to the beginning of the list
*
* @num: data to be added
*/
void add_node(stack_t **stack, int num)
{
	stack_t *first_stack = NULL;

	first_stack = malloc(sizeof(stack_t));
	if (first_stack == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}

	first_stack->n = num;
	first_stack->prev = NULL;
	first_stack->next = NULL;

	if (*stack == NULL)
		*stack = first_stack;
	else
	{
		first_stack->next = *stack;
		(*stack)->prev = first_stack;
		*stack = first_stack;
	}
}
