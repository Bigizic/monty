#include "monty.h"
/* header */

/**
* _pint - prints the top of stack
*
* @stack: head of list
*
* @line_number: counter
*
* Return: void
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
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
