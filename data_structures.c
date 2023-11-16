#include "monty.h"

/**
 * myStack - sets the format of the data to a stack (LIFO)
 * @start: A pointer to the head of the stack
 * @iterator: The line number where the opcode appears
 */
void myStack(stack_t **start, unsigned int iterator)
{
(void)iterator;
(void)start;
}

/**
 * myQueue - sets the format of the data to a queue (FIFO)
 * @start: A pointer to the head of the stack
 * @iterator: The line number where the opcode appears
 */
void myQueue(stack_t **start, unsigned int iterator)
{
stack_t *current = *start;

(void)iterator;
if (current == NULL || current->next == NULL)
return;

while (current->next != NULL)
current = current->next;

current->next = *start;
(*start)->prev = current;
*start = (*start)->next;
(*start)->prev->next = NULL;
(*start)->prev = NULL;
}

