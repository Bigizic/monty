#include "monty.h"
/* header */

/**
* _sub - subtracts the top element of the stack from the second top element
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int i, n;

	h = *stack;

	for (n = 0; h != NULL; n++)
		h = h->next;

	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h = *stack;
	i = h->next->n - h->n;
	h->next->n = i;
	*stack = h->next;
	free(h);
}
