#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct struct_op - struct to store the readed file in a buffer.
 * @f_d: variable that takes the lines of the file '.m'.
 * @buffer: buffer to store the readed files.
 * @n: data that indicates to do something at a function.
 *
 * Description: struct to stores the function to operate the
 *              stack.
 */
typedef struct struct_op
{
	FILE *f_d;
	char *buffer;
	char *n;
} op_struct;

op_struct var;
void (*fs(char *bf, unsigned int l))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
int _isdigit(void);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **node, unsigned int line_number);
void swap(stack_t **node, unsigned int line_number);
void add(stack_t **node, unsigned int line_number);
void nop(stack_t **node, unsigned int line_number);
void free_stack(stack_t *stack);
stack_t *addNode(stack_t **head, char *n);
void sub(stack_t **node, unsigned int line_number);
int length(stack_t *node);
void div(stack_t **node, unsigned int line_number);

#endif /* _MONTY_H_ */
