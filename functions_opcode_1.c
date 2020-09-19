#include "monty.h"
/**
 * fs - struct to check the order to executes functions.
 * @bf: Buffer to store the line.
 * @l: Stores the line number in the file.
 * Return: The selected name of the function or NULL.
 */
void (*fs(char *bf, unsigned int l))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{NULL, NULL}
	};
	(void)l;
	for (; functions[i].opcode != NULL; i++)
	{
		if (strcmp(bf, functions[i].opcode) == 0)
			return (functions[i].f);
	}
	return (NULL);
}
/**
 * push - adds a new node in the stack.
 * @node: node to be added in the stack.
 * @line_number: lines number.
 * Return: void.
 */
void push(stack_t **node, unsigned int line_number)
{
	int digit;

	digit = _isdigit();
	if (digit == 1 || !(var.n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	addNode(&(*node), var.n);
}
/**
 * pall - print the data stored in a node of the stack.
 * @node: Node that contains the data to print.
 * @line_number: Number of the line that is stored the function.
 * Return: void.
 */
void pall(stack_t **node, unsigned int line_number)
{
	stack_t *nodePall = *node;
	(void)line_number;

	while (nodePall)
	{
		printf("%d\n", nodePall->n);
		nodePall = nodePall->next;
	}
}
/**
 * pint - prints the value at the top of the stack.
 * @node: node to be printed.
 * @line_number: Number of the line of the file.
 * Return: void.
 */
void pint(stack_t **node, unsigned int line_number)
{
	stack_t *topNode = *node;

	if (!topNode)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", topNode->n);
}
/**
 * pop - Removes the top element of the stack.
 * @node: Node to be deleted of the stack.
 * @line_number: Number of the line in the file.
 * Return: void.
 */
void pop(stack_t **node, unsigned int line_number)
{
	stack_t *deleteNode = *node;

	if (!deleteNode)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	*node = (*node)->next;
	free(deleteNode);
}
