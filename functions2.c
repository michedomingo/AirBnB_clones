#include "monty.h"

/**
 * create_newNode - create new node
 * @n: value to store in new node
 * Return: new node
 */
stack_t *create_newNode(int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newNode);
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	return (newNode);
}

/**
 * push_onto_stack - pushes a node onto a stack
 * @stack: double pointer to head of doubly linked list
 * @line_number: line number
 */

int int_val = 0;
void push_onto_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void) line_number;

	node = create_newNode(int_val);
	/* if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(node);
		exit(EXIT_FAILURE);
		} */
	if (*stack == NULL)
		node->next = NULL;
	else
		node->next = *stack;

	*stack = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * print_stack - prints the value at the top of the stack
 * @stack: double pointer to head of doubly linked list
 * @line_number: line number
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (!stack)
	{
		exit(EXIT_FAILURE);
	}

	while (stack)
	{
		printf("help me print_stack");
		/* printf("%d\n", stack->n); */
		stack = stack->next;
	}
}

/**
 * print_top_of_stack -
 * @stack: double pointer to head of doubly linked list
 * @line_number: line number
 void print_top_of_stack(stack_t **stack, unsigned int line_number)
 */
