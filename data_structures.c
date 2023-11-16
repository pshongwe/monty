#include "monty.h"

/**
 * myQueue - sets the format of the data to a queue (FIFO)
 * @start: A pointer to the head of the stack
 * @iterator: The line number where the opcode appears
 */
void myQueue(stack_t **start, unsigned int iterator)
{
stack_t *current = *start;
stack_t *newStart = NULL;

(void)iterator;

if (current == NULL || current->next == NULL)
return;

while (current != NULL)
{
stack_t *next = current->next;
current->next = newStart;
current->prev = NULL;
if (newStart != NULL)
newStart->prev = current;
newStart = current;
current = next;
}

*start = newStart;
}

/**
 * myStack - sets the format of the data to a stack (LIFO)
 * @start: A pointer to the head of the stack
 * @iterator: The line number where the opcode appears
 */
void myStack(stack_t **start, unsigned int iterator)
{
stack_t *current = *start;
stack_t *newStart = NULL;

(void)iterator;

if (current == NULL || current->next == NULL)
return;

while (current != NULL)
{
stack_t *next = current->next;
current->next = newStart;
current->prev = NULL;
if (newStart != NULL)
newStart->prev = current;
newStart = current;
current = next;
}

*start = newStart;
}
