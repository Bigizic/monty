#include "monty.h"
/* header */

/**
* main - entry point
*
* @ac: number of arguments
*
* @av: argument
*
* Return: 0 if success
*/
int main(int ac, char *av[])
{
	unsigned int line_number = 1;
	char *buffer = NULL, *string = NULL;
	stack_t *stack_cp = NULL;
	FILE *read_stream = NULL;
	size_t buffer_len 0;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_stream = fopen(av[1], "r");
	if (read_stream == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buffer_len, read_stream) != -1)
	{
		if (buffer != NULL)
			_opcodes(&stack, line_number, buffer);
		line_number++;
	}
	free_stack(stack);

	stack = NULL;
	fclose(read_stream);
	exit(EXIT_SUCCESS);
}

/**
* _opcodes - read opcode and compare it to available opcodes
*
* @stack: pointer to begining of the list
*
* @line_number: counter for number of lines of the file
*
* @buffer: opcode to execute
*/
void _opcodes(stack_t **stack, unsigned int line_number, char *buffer)
{
	int i = 0;

	instruction_t my_opcodes[] = {
		{"push", _push},
		{NULL, NULL};
	}

	while (my_opcodes[i].opcode)
	{
		if (strcmp(my_opcodes[i].opcode, buffer) == 0)
		{
			my_opcode[i].f(stack, line_number);
			return;
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, code);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
