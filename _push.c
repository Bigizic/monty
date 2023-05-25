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
	char *opcode_arg = strtok(NULL, " ");
	int data;

	if (opcode_arg == NULL || !is_number(opcode_arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	data = atoi(opcode_arg);
	add_node(stack, data);

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

	if (*stack == NULL)
		*stack = first_stack;
	else
	{
		first_stack->next = *stack;
		(*stack)->prev = first_stack;
		*stack = first_stack;
	}
}


/**
* add_node_ - pushes an element to the stack
*
* @stack: double pointer
*
* @argument: int push
*
* Return: void
*/
void add_node_(stack_t **stack, int argument)
{
	stack_t *stack_cp, *last_stack;

	stack_cp = malloc(sizeof(stack_t));

	stack_cp->n = argument;
	stack_cp->prev = NULL;
	stack_cp->next = NULL;

	if (*stack == NULL)
		*stack = stack_cp;

	else
	{
		last_stack = *stack;
		while (last_stack->next != NULL)
			last_stack = last_stack->next;

		stack_cp->next = NULL;
		stack_cp->prev = last_stack;
		last_stack->next = stack_cp;
	}
}

/**
* is_number - checks if a string represents a valid number
*
* @str: string to check
*
* Return 1 on sunccess otherwise 0
*/
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;
	for (; *str != '\0'; str++)
	{
		if (*str < '0' || *str > '9')
			return (0);
	}
	return (1);
}
