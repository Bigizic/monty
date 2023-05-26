#include "monty.h"
/* header */

/**
* _pstr -  prints the string starting at the top of the stack,
* followed by a new line. integer stored is treated as ASCII value
*
* @stack: head
*
* @line_number: counter
*
* Return: void
* */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	(void)line_number;

	h = *stack;

	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
