#include "monty.h"
/* header */

#define BUFFER_SIZE 1024

/**
* main - entry point
*
* @ac: number of arguments
*
* @av: argument
*
* Return: 0 if success
*/
int main(int argc, char *argv[])
{
	unsigned int line_number = 1;
	char buffer[BUFFER_SIZE];
	FILE *read_stream;
	char *arg, *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_stream = fopen(argv[1], "r");
	if (read_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, BUFFER_SIZE, read_stream))
	{
		line_number++;

		buffer[strcspn(buffer, "\n")] = '\0';
		opcode = strtok(buffer, " ");
		arg = strtok(NULL, " ");
		stack->n = atoi(arg);
		_opcodes(&stack, opcode, line_number);
	}
	fclose(read_stream);
	free_stack(&stack);
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
void _opcodes(stack_t **stack, char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		_push(stack, line_number);
		return;
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		_pall(stack, line_number);
		return;
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
