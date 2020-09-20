#include "monty.h"
/**
 * _mul - Multiplies the top two elements of the stack.
 *        The result is then stored in the second node,
 *        and the first node is removed.
 * @node: Points to the top of the stack.
 * @line_number: Number of the line of the instruction.
 * Return: void. 
 */
void _mul(stack_t **node, unsigned int line_number)
{
        if (length(*node) < 2)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                free(var.buffer);
                free_stack(*node);
                fclose(var.f_d);
                exit(EXIT_FAILURE);
        }
        (*node)->next->n *= (*node)->n;
        pop(node, line_number);
}

/**
 * _mod - Computes the remainder of the top two elements of the stack
 *        from the second top element.
 *        The result is then stored in the second node,
 *        and the first node is removed.
 * @node: Points to the top of the stack.
 * @line_number: Number of the line of the instruction.
 * Return: void.
 */
void _mod(stack_t **node, unsigned int line_number)
{
	if (length(*node) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
	(*node)->next->n %= (*node)->n;
	pop(node, line_number);
}
/**
 * pchar - Prints the integer stored in the top of the stack
 *         as its ascii value representation.
 * @node: Points to the top of the stack.
 * @line_number: Number of the line of the instruction.
 * Return: void.
 */
void pchar(stack_t **node, unsigned int line_number)
{
	if (!(*node))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
                free(var.buffer);
                free_stack(*node);
                fclose(var.f_d);
                exit(EXIT_FAILURE);
	}
	if ((*node)->n < 0 || (*node)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
                free(var.buffer);
                free_stack(*node);
                fclose(var.f_d);
                exit(EXIT_FAILURE);
	}
	putchar((char)(*node)->n);
	putchar('\n');
}
void pstr(stack_t **node, unsigned int line_number)
{
	stack_t *tmp = *node;

	(void)line_number;
	if (!(*node))
        {
                printf("\n");
                free(var.buffer);
                free_stack(*node);
                fclose(var.f_d);
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (!(tmp->n < 0 || tmp->n > 127))
		{
			putchar((char)tmp->n);
			tmp = tmp->next;
		}
	}
	putchar('\n');
}
