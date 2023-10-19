#include "monty.h"
/**
 * push - function to push an element onto the stack
 * @stack: pointer to stack
 * @value: data
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - function to print all elements in the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * initialize - initializes stack
 * @stack: stack
 */
void initialize(stack_t *stack)
{
	stack->n = 0;
	stack->prev = NULL;
	stack->next = NULL;
}
