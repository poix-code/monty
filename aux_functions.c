#include "monty.h"
/**
 * addNode - adds a new node at the beginning of a stack.
 * @head: pointer to the head of a dlinked list.
 * @n: data to store in the struct.
 * Return: The address of the new node.
 */
stack_t *addNode(stack_t **head, char *n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed");
		free(var.buffer);
		free_stack(*head);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	if ((*head) == NULL)
	{
		newNode->n = atoi(n);
		newNode->next = NULL;
		newNode->prev = NULL;
		*head = newNode;
	}
	else
	{
		newNode->n = atoi(n);
		newNode->next = *head;
		newNode->prev = (*head)->prev;
		(*head)->prev = newNode;
		*head = newNode;
	}
	return (newNode);
}
/**
 * free_stack - frees the memory previous allocated.
 * @node: the node to be released.
 * Return: void.
 */
void free_stack(stack_t *node)
{
	if (node)
	{
		free_stack(node->next);
		free(node);
	}
}
/**
 * _isdigit - check if the character is a digit.
 * Return: 0 if its a digit else 1.
 */
int _isdigit(void)
{
	int i;

	if (!(var.n))
	{
		return (1);
	}
	i = var.n[0] == '-' ? 1 : 0;
	while (var.n[i] != 0)
	{
		if (var.n[i] < '0' || var.n[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/**
 * length - Checks the length of a list
 * @node: points to head of the stack.
 * Return: the number of elements.
 */
int length(stack_t *node)
{
	int i;

	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}
/**
 * add_dnodeint_end - adds a new node at the end of the stack.
 * @node: node to be added.
 * @n: data to store in the node.
 * Return: the address of the new node.
 */
stack_t *add_dnodeint_end(stack_t **node, const int n)
{
	stack_t *newNode = NULL;

	if (!node)
		return (NULL);
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed");
		free(var.buffer);
		free_stack(*node);
		fclose(var.f_d);
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	if (!*node)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*node = newNode;
	}
	else
	{
		newNode->next = *node;
		while (newNode->next->next)
			newNode->next = newNode->next->next;
		newNode->next->next = newNode;
		newNode->prev = newNode->next;
		newNode->next = NULL;
	}
	return (newNode);
}
