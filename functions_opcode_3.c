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
	if ((*node) == 0)
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
