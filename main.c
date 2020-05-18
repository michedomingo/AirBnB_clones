#include "monty.h"

/**
 * main - entry point for monty byte code interpreter
 * @argc: argument count (should be 2)
 * @argv: command line arguments (av[1] should be filename)
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *monty_file; /* fopen("file_name", "mode"); stream for getline() */
	char *line = NULL; /* stores address of buffer containing text from getline() */
	char **commands; /* stores strtok'd tokens from get_tokens() */
	unsigned int line_number = 0; /* count number of lines read after getline() looped */
	size_t len = 0; /*  buffer size of line in bytes from getline() */
	/* size_t *stack = NULL; */


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
	/* getline reads an entire line from stream, allocates buffer for line */
	while ((getline(&line, &len, monty_file)) != -1) /* return -1 on failure to read line (including EOF condition) */
	{
		line_number++;
		commands = get_tokens(line);
		printf("line number: %d\n", line_number);
		printf("token1: line[0] %s\n", commands[0]);
		printf("token2: line[1] %s\n", commands[1]);
		get_function(commands);
	}

	free(line);
	free(commands);
	fclose(monty_file);
	return (0);
}
