#include "monty.h"

/**
 *  _pop - a new item to the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	if (!aux->next)
	{
		*stack = NULL;
		free(aux);
	}
	else
	{
	*stack = aux->next;
	aux->next->prev = NULL;
	free(aux);
	}
}

