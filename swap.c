#include "monty.h"
/* header */

/**
* _swap - swap the top two elements
*
* @stack: head
*
* @line_number: counter
*
* Return: void
*/
void _swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.buffer);
		_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h = *stack;
	x = h->n;
	h->n = h->next->n;
	h->next->n = x;
}
