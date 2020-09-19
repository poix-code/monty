#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @node: node to be swaped with next one in the stack.
 * @line_number: number of the line in the file.
 * Return: void.
 */
void swap(stack_t **node, unsigned int line_number)
{
	stack_t *nodeSwap = *node;

	if (*node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	nodeSwap = (*node)->next;
	(*node)->prev = (*node)->next;
	(*node)->next = nodeSwap->next;
	nodeSwap->prev = NULL;
	(*node)->prev = nodeSwap;
	if (nodeSwap->next)
		nodeSwap->next->prev = *node;
	nodeSwap->next = *node;
	(*node) = (*node)->prev;
}
/**
 * nop - This opcode does not do anything.
 * @node: element to do nothing.
 * @line_number: Number of the line of the instruction.
 * Return: void.
 */
void nop(stack_t **node, unsigned int line_number)
{
	(void)node;
	(void)line_number;
}
/**
 * add - Adds the top two elements of the stack.
 *       The result is stored in the second node,
 *       and the first node is removed.
 * @node: Pointer to the top of the stack.
 * @line_number: Number of the line of the instruction.
 * Return: void.
 */
void add(stack_t **node, unsigned int line_number)
{
	if (*node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	(*node)->next->n = (*node)->n + (*node)->next->n;
	pop(node, line_number);
}
/**
 * sub - Subtracts the top element of the stack from the second top element.
 *       The result is then stored in the second node,
 *       and the first node is removed.
 * @node: Points to the top of the stack.
 * @line_number: Number of the line of the instruction.
 * Return: void.
 */
void sub(stack_t **node, unsigned int line_number)
{
	if (length(*node) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	(*node)->next->n -= (*node)->n;
	pop(node, line_number);
}
/**
 * div - Divides the top two elements of the stack from the second top element.
 *       The result is then stored in the second node,
 *       and the first node is removed.
 * @node: Points to the top of the stack.
 * @line_number: Number of the line of the instruction.
 * Return: void.
 */
void div(stack_t **node, unsigned int line_number)
{
	if (length(*node) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                free(var.buffer);
                free_stack(*node);
                fclose(var.f_d);
                exit(EXIT_FAILURE);
	}
	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	(*node)->next->n /= (*node)->n;
	pop(node, line_number);
}
