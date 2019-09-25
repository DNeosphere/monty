#include "monty.h"
/**
 *  _sub - subs the two first elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int substraction;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	substraction = (*stack)->n;
	(*stack)->next->n -= substraction;
	_pop(stack, line_number);
}
/**
 *  _mul - Add the two first elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n;
	(*stack)->next->n *= mul;
	_pop(stack, line_number);
}
