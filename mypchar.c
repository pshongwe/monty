#include "monty.h"

/**
 * myPchar - rints the char at the top of the stack
 * followed by a new line 
 * @start: A pointer to the head of the stack
 * @iterator: The line number where the opcodes appears
 */
void myPchar(stack_t **start, unsigned int iterator)
{
	if (*start == NULL || (*start)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", iterator);
		fclose(mont.myfile);
		free(mont.subjects);
		free_allstacks(*start);
		exit(EXIT_FAILURE);
	}
	if (!isascii((*start)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", iterator);
		fclose(mont.myfile);
		free(mont.subjects);
		free_allstacks(*start);
		exit(EXIT_FAILURE);
	}

	putchar('0' + ((*start)->n));
	putchar('\n');
	myPop(start, iterator);
}
