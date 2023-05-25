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
	size_t i, len;
	char *argument_cp = argument;

	argument_cp = strtok(NULL, " \t\r\n\v\f");

	len = strlen(argument_cp);
	if (argument_cp == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
	{
		if (!isdigit(argument_cp[i]) && argument_cp[0] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			printf("Hello2\n");
			exit(EXIT_FAILURE);
		}
	}
	add_node(stack, atoi(argument_cp));
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
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
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
