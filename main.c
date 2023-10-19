#include "monty.h"
/**
 * main - entry point
 * @argc: argc
 * @argv: argv
 * Return: 0 at success
 */
int main(int argc, char *argv[])
{
	stack_t *my_stack = NULL;
	unsigned int line_number = 0;
	char line[100];
	int value;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		line[strlen(line) - 1] = '\0';

		if (strncmp(line, "push", 4) == 0)
		{
			value = atoi(line + 5);
			if (value == 0 && line[5] != '0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				goto cleanup;
			}
			push(&my_stack, value);
		}
		else if (strcmp(line, "pall") == 0)
		{
			pall(&my_stack, line_number);
		}
		else if (strcmp(line, "pop") == 0)
		{
			pop(&my_stack, line_number);
		}
	}

cleanup:
	fclose(file);

	while (my_stack)
	{
		stack_t *temp = my_stack;

		my_stack = my_stack->next;
		free(temp);
	}

	return (EXIT_SUCCESS);
}
