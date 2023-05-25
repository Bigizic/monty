#include "monty.h"
/* header */

/**
* _pop - removes the top
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
