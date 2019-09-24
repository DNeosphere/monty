#include "monty.h"
/**
 * _push - adds a new item to the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	n_node->n = value;
	n_node->prev = NULL;
	n_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = n_node;
	*stack = n_node;
}
/**
 * _pall - print all elements of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if (temp)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
