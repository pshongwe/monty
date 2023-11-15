#include "monty.h"

/**
 * myPall - prints the stack
 * @start: head of the stack
 * @iterator: counter not  used
 * Return: nothing to return
 */
void myPall(stack_t **start, unsigned int iterator)
{
	stack_t *st;
	(void)iterator;

	st = *start;
	if (st == NULL)
		return;

	while (st)
	{
		printf("%d\n", st->n);
		st = st->next;
	}
}
