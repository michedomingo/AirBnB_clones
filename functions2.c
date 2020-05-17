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

void push_onto_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	stack_t *temp;
	(void) line_number;

	/* node = create_newNode(line_number); */
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(node);
		exit(EXIT_FAILURE);		
	}
	/* node->n = [value from arg?] */
	node->prev = NULL;
	node->next = NULL;

	if (!*stack)
	{
		node->next = NULL;
		*stack = node;
		return (*stack);
	}
	temp = *stack;
	node->next = temp;
	temp->next = node;
	*stack = node;
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
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * print_top_of_stack -
 * @stack: double pointer to head of doubly linked list
 * @line_number: line number
 void print_top_of_stack(stack_t **stack, unsigned int line_number)
 */