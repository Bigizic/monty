#include "monty.h"
/* header */

/**
* _mul - multiplies the second top element of the stack with the top element
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int len = 0, x;
	
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	x = h->next->n * h->n;
	h->next->n = x;
	*stack = h->next;
	free(h);
}
