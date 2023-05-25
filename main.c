#include "monty.h"
char *data = NULL;

/**
* main - entry point
*
* @ac: vector counter
*
* @av: char
*
* Return: 0 if success
*/
int main(int ac, char *av[])
{
	FILE *monty_ptr;
	char buffer[BUFFER_SIZE], *get_line;
	unsigned int line_number = 1;
	stack_t **stack = malloc(sizeof(stack_t *));

	*stack = NULL;
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}
	monty_ptr = fopen(av[1], "r");
	if (monty_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		get_line = fgets(buffer, 255, (FILE *)monty_ptr);
		if (get_line == NULL)
			break;
		if (space_check(get_line) != 0)
			execute_opcode(stack, line_number, get_line);
		line_number++;
	}
	_free_stack(stack);
	fclose(monty_ptr);
	exit(EXIT_FAILURE);
}

/**
* execute_opcode - compares op_code
*
* @stack: header to head
*
* @line_number: unsigned int type
*
* @op_code: char type
*
* Return: void
*/
void execute_opcode(stack_t **stack, unsigned int line_number, char *op_code)
{
	int i;
	char *delim = " ";
	char *codes;

	instruction_t func[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; op_code[i] != '\0'; i++)
	{
		if (op_code[i] == '\n')
			op_code[i] = '\0';
	}

	codes = strtok(op_code, delim);
	data = strtok(NULL, delim);
	for (i = 0; i < 13; i++)
	{
		if (strcmp(func[i].opcode, codes) == 0)
		{
			func[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_code);
	if (*stack != NULL)
		_free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
* _free_stack - frees allocated memory
*
* @stack: stack_t type
*
* Return: void
*/
void _free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
	free(stack);
}
