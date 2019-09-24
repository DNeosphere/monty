#include "monty.h"

int is_num(char *token)
{
	int i = 0, res = 1;

	while (token[i] != '\0')
	{
		if (token[i] >= 48 && token[i] <= 57)
		{
			i++;
			continue;
		}
		else
			return (res = 0);
		i++;
	}
	return (res);
}

