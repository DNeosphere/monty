#include "monty.h"

int main(int arc, char *arv[])
{
	instruction_t ins_arr[] = {{"push", _push}, {"pall", _pall}};
	stack_t *stack = NULL;
	int file_op, i = 0, line = 1;
	char *buff, *token, *token_push;
	size_t *n = 30;

	if (arc != 2)
		printf("USAGE: monty file");
	file_op = open(arv[1], RDONLY);
	if (file_op == -1)
		printf("Error: Can't open file %s", arv[1]);
	while (getline(&buff, n, file_op))
	{
		token = strtok(buff, " \t\n\r");
		while (i < 3)
		{
			if (strcmp(token, ins_arr[i].opcode) == 0)
			{
				if (strcmp(token, "push") == 0)
				{
					token_push = strtok(NULL, " \t\n\r");
					if (is_num(token_push) == 0)
						printf("L%d: usage: push integer", line);
					value = atoi(token_push);
				}
				ins_arr[i].f(&stack, line);
			}
			else if (i == 2)
				printf("L%d: unknown instruction %s", line, token);
			i++;
		}
		line++;
	}
}

