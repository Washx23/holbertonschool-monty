#include "monty.h"
/**
 * _swap -  This function swaps the value of the element at the
 * top of the stack with the value of the second element in the stack.
 * @stack: stack where all our elements will be.
 * @numbers: numbers within the stack.
 */
void _swap(stack_t **stack, unsigned int numbers)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", numbers);
		exit(EXIT_FAILURE);
	}

	int val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = val;
}
/**
 * _add - opcode that adds the first two elements of the stack.
 * @stack: stack where all our elements will be.
 * @numbers: numbers within the stack.
 */
void _add(stack_t **stack, unsigned int numbers)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", numbers);
		exit(EXIT_FAILURE);
	}

	int sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, numbers);
	(*stack)->n = sum;
}
/**
 * _nop - opcode that doesn’t do anything.
 * @stack: stack where all our elements will be.
 * @numbers: numbers within the stack.
 */
void _nop(stack_t **stack, unsigned int numbers)
{
	(void) stack, (void) numbers;
}
/**
 * _pop - This function removes the element at the top of the stack.
 * @stack: stack where all our elements will be.
 * @numbers: numbers within the stack.
 */
void _pop(stack_t **stack, unsigned int numbers)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", numbers);
		exit(EXIT_FAILURE);
	}

	stack_t *head = *stack;
	*stack = head->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(head);
}