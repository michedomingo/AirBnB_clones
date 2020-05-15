#include "monty.h"

/**
 * main - entry point for monty byte code interpreter
 * @argc: argument count (should be 2)
 * @argv: command line arguments (av[1] should be filename)
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char *line = NULL;
	char **commands;
	size_t len = 0;
	ssize_t nread;
	int line_number = 0;


	/* only one arg to program allowed */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* getline returns #chars read (excluding '\0') */
	while ((nread = getline(&line, &len, monty_file)) != -1)
	{
		printf("Retrieved line of length %zu:\n", nread);
		line_number++;
		commands = get_tokens(line);
		printf("line number: %d\n", line_number);
		printf("token1: line[0] %s\n", tokens[0]);
		printf("token2: line[1] %s\n", tokens[1]);
	}


	free(line);
	fclose(monty_file);
	return (0);
}

/**
 * get_tokens -
 * @input:
 * Return:
 */
char **get_tokens(char *input)
{
	int i;
	char *str_tok;
	char **tokens;

	tokens = malloc(sizeof(size_t);
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str_tok = strtok(input, DELIM);

	i = 0;
	while (str_tok)
	{
		tokens[i] = str_tok;
		i++;
		str_tok = strtok(NULL, DELIM);
	}
	return (tokens);
}
