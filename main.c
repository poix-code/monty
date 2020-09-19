#include "monty.h"

op_struct var = {NULL, NULL, NULL};

/**
 * main - Take the monty commands of a file.
 * @argc: amount of arguments to main.
 * @argv: arguments to main.
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *node = NULL;
	size_t length = 0;
	char *text = NULL;
	unsigned int lines = 0;
	void (*opCode)(stack_t **stack, unsigned int line_number) = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	var.f_d = fopen(argv[1], "r");
	if (!var.f_d)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&var.buffer, &length, var.f_d) != EOF)
	{
		lines++;
		text = strtok(var.buffer, "\t\n ");
		if (text != NULL && text[0] != '#')
		{
			opCode = fs(text, lines);
			if (!opCode)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", lines, text);
				free_stack(node);
				free(var.buffer);
				fclose(var.f_d);
				exit(EXIT_FAILURE);
			}
			var.n = strtok(NULL, " \t\n");
			opCode(&node, lines);
		}
	}
	free(var.buffer);
	free_stack(node);
	fclose(var.f_d);
	exit(EXIT_SUCCESS);
}
