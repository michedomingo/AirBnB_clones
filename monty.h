#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DELIM "\n\r "

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int int_val;

char **get_tokens(char *input);
instruction_t *get_function(char **token);
stack_t *create_newNode(int n);

void push_onto_stack(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);

/**
void print_top_of_stack(stack_t **stack, unsigned int line_number);
void remove_top_of_stack(stack_t **stack, unsigned int line_number);
void swap_top2_of_stack(stack_t **stack, unsigned int line_number);
void add_top2_of_stack(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);

	instruction_t opcode_list[] = {
		{"push", push_onto_stack},
		{"pall", print_stack},
		{"pint", print_top_of_stack},
		{"pop", remove_top_of_stack},
		{"swap", swap_top2_of_stack},
		{"add", add_top2_of_stack},
		{"nop", do_nothing},
		{NULL, NULL}
*/
#endif
