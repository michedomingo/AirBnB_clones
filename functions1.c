#include "monty.h"

/**
 * get_tokens - breaks string into a two-level hierarchy of tokens
 * @input: line to split from file
 * Return: tokens for command and value
 **/
char **get_tokens(char *input)
{
	int i;
	char *str_tok;
	char **tokens;
/* size_t can store the maximum size of a theoretically possible object of any type */
	tokens = malloc(sizeof(size_t));
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str_tok = strtok(input, DELIM);

	i = 0;
	while (str_tok)
	{
		tokens[i] = str_tok; /* if token is found, return pointer beginning of token */
		str_tok = strtok(NULL, DELIM);
		i++;
		printf("get_tokens[%d]: %s\n", i, tokens[i]);
	}
	return (tokens);
}

/**
 * get_function - match opcode with associated funtion pointer
 * @opcode: function to search for
 * Return: pointer to opcode function
 **/
instruction_t *get_function(char **token)
{
	instruction_t opcode_list[] = {
		{"push", push_onto_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 2; i++)
	{
		if (strcmp(token, opcode_list[i].opcode) == 0)
			printf("woot woot\n");
			return (opcode_list[i].f);
	}
	/* fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token[0]); */
	/* exit(EXIT_FAILURE); */
	return (NULL);
}
