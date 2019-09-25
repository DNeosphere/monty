#include "monty.h"
/**
 * _push - adds a new item to the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	(void)line_number;

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
	(void)line_number;

	if (temp)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
/**
 * _pint - prints the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _swap - swaps the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int first_n, sec_n;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_n = temp->n;
	sec_n = temp->next->n;
	temp->next->n = first_n;
	temp->n = sec_n;
}
