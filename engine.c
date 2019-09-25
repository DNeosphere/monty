#include "monty.h"
int value;
/**
 * main - engine to integrate the monty interpreter
 * @arc: argument count
 * @arv: argument vector
 * Return: 0 on success otherwise EXIT_FAILURE
 */
int main(int arc, char *arv[])
{
	instruction_t ins_arr[] = {{"push", _push}, {"pall", _pall}};
	stack_t *stack = NULL;
	FILE *file_op;
	int i = 0, line = 1;
	char *buff, *token, *token_push;
	size_t size = 30;

	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_op = fopen(arv[1], "r");
	if (!file_op)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &size, file_op) != EOF)
	{
		token = strtok(buff, " \t\n\r");
		i = 0;
		while (i < 3)
		{
			if (strcmp(token, ins_arr[i].opcode) == 0)
			{
				if (strcmp(token, "push") == 0)
				{
					token_push = strtok(NULL, " \t\n\r");
					if (is_num(token_push) == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
					value = atoi(token_push);
				}
				ins_arr[i].f(&stack, line);
				break;
			}
			else if (i == 1)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		line++;
	}
	return (0);
}
