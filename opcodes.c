#include "monty.h"
/**
 * _push - opcode that pushes an element to the stack.
 * @stack: stack where all our elements will be.
 * @line_number: numbers within the stack.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *str = strtok(NULL, "\t\n ");
	if (!str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(str);
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
/**
 * _pall - prints all the values , starting from the top of the stack.
 * @stack: stack where all our elements will be.
 * @line_number: numbers within the stack.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stack where all our elements will be.
 * @line_number: numbers within the stack.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
