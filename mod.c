#include "monty.h"
/* header */

/**
* _mod - computes the rest of the division of the second top
* element of the stack by the top element of the stack
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, x;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	x = h->next->n % h->n;
	h->next->n = x;
	*stack = h->next;
	free(h);
}
