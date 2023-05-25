#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE

/* headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024


/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* bus_s - a bus like struct that contains file name and file argument
* @data: char type
* @buffer: buffer to store file name
* @file: file opener
* @lifi: status
*
*/
typedef struct bus_s
{
	char *data;
	char *buffer;
	FILE *file;
	int lifi;
} bus_t;

extern bus_t bus;

/* opcode prototypes */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);





/* function prototypes */
void execute_opcode(stack_t **stack, unsigned int line_number,
		char *op_code, FILE *monty_ptr);
void _free_stack(stack_t *stack);
void add_node(stack_t **stack, int i);
void add_queue(stack_t **stack, int i);


#endif
