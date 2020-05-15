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
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	return (newNode);
}

/**
 * get_function -
 * @opcode: function to search for
 * Return: pointer to opcode function, otherwise null
 **/

get_function()
{
	instruction_t opcode[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{NULL, NULL}
	};

}
