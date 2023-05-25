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
	char *buffer = NULL;
	stack_t *stack_cp = NULL;
	FILE *read_stream = NULL;
	size_t buffer_len = 0;
	char *arg = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_stream = fopen(av[1], "r");
	if (read_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &buffer_len, read_stream) != -1)
	{
		arg = strtok(buffer, " ");
		if (arg != NULL && arg[0] != '#')
			_opcodes(&stack_cp, line_number, arg);
		line_number++;
	}
	free_stack(stack_cp);

	stack_cp = NULL;
	free(buffer);
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
* @buffer_cp: opcode to execute
*/
void _opcodes(stack_t **stack, unsigned int line_number, char *buffer_cp)
{
	int i = 0;

	instruction_t my_opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (my_opcodes[i].opcode)
	{
		if (strcmp(my_opcodes[i].opcode, buffer_cp) == 0)
		{
			my_opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, buffer_cp);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
