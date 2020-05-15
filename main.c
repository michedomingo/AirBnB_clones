#include "monty.h"

/**
 * main - entry point for monty byte code interpreter
 * @argc: argument count (should be 2)
 * @argv: command line arguments (av[1] should be filename)
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	/* only one arg to program allowed */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if(monty_file == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* WIP: trying to figure out operation code parsing  */

	return (0);
}
