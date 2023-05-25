#include "monty.h"
/* header */

/**
* stack_default - default mode for stack
*
* @stack: double pointer to head
*
* @line_number: counter for line number of the file
*/
void stack_default(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	global_variable = 's';
}
