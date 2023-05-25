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
	char *arg = strtok(NULL, " \n");


	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_node(stack, atoi(arg));
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
	stack_t *first_stack;

	first_stack = malloc(sizeof(stack_t));
	if (first_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first_stack->n = num;
	first_stack->prev = NULL;
	first_stack->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = first_stack;
	*stack = first_stack;
}


/**
* is_number - checks if a string represents a valid number
*
* @str: string to check
*
* Return: 1 on sunccess otherwise 0
*/
int is_number(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
