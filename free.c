#include "monty.h"
/**
 * free_stack - frees stack
 * @stack: stack
 */
void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
/**
 * execute_opcode - executes opcode
 * @my_stack: stack
 * @opcode: opcode
 * @line_number: line number
 * @line: line
 */
void execute_opcode(stack_t **my_stack, char *opcode,
		unsigned int line_number, char *line)
{
	if (strcmp(opcode, "push") == 0)
	{
		int value = atoi(line + 5);

		push(my_stack, value);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(my_stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(my_stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(my_stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(my_stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(my_stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(my_stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
