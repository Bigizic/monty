#include "monty.h"

/**
* _pint - prints the vslue at the top of the stack
*
* @stack: head list
*
* @line_number: error line counter
*
* Return: void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->prev == NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
		printf("%d\n", (*stack)->n);
	}
}
