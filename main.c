#include "monty.h"
/**
 * main - entry point
 * @argc: argc
 * @argv: argv
 * Return: 0 at success
 */
int main(int argc, char *argv[])
{
	stack_t *my_stack;
	unsigned int line_number;
	char line[100];
	int value;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	my_stack = NULL;
	line_number = 0;
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
				return (EXIT_FAILURE);
			}
			push(&my_stack, value);
		}
		else if (strcmp(line, "pall") == 0)
		{
			pall(&my_stack, line_number);
		}
		else if (strcmp(line, "pint") == 0)
		{
			pint(&my_stack, line_number);
		}
	}

	fclose(file);
	return (0);
}
