#include "monty.h"

/**
 * mySub - subtracts the top two elements of the stack
 * @start: A pointer to the head of the stack
 * @iterator: The line number where the opcodes appears
 */
void mySub(stack_t **start, unsigned int iterator)
{
	if (*start == NULL || (*start)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", iterator);
		fclose(mont.myfile);
		free(mont.subjects);
		free_allstacks(*start);
		exit(EXIT_FAILURE);
	}

	(*start)->next->n -= (*start)->n;
	myPop(start, iterator);
}
