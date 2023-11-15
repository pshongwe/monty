#include "monty.h"

int run(char *subjects, stack_t **stack, unsigned int iterator, FILE *myfile);

/**
 * run - executes the code
 * @stack: start of the linked list
 * @iterator: counts the line
 * @myfile: pointer to the file structure
 * @subjects: pointer to char representing contents
 * Return: nothing to return
 */
int run(char *subjects, stack_t **stack, unsigned int iterator, FILE *myfile)
{
	instruction_t myops[] = {
		{"push", myPush}, {"pall", myPall},
		{"pint", myPint},
		{"pop", myPop},
		{"swap", mySwap},
		{"add", myAdd},
		{"sub", mySub},
		{"div", myDiv},
		{"mul", myMul},
		{"mod", myMod},
		{"pchar", myPchar},
		{"nop", myNop},
		{NULL, NULL}
	};

	unsigned int x = 0;
	char *myopcodes;

	/* Tokenize the input line to get opcode */
	myopcodes = strtok(subjects, " \n\t");

	if (myopcodes && myopcodes[0] == '#')
		return (0);

	mont.av = strtok(NULL, " \n\t");

	/* Loop through the instruction array to find match for opcodes */
	while (myops[x].opcode && myopcodes)
	{
		if (strcmp(myopcodes, myops[x].opcode) == 0)
		{
			myops[x].f(stack, iterator);
			return (0);
		}
		x++;
	}

	/* If opcode is not found print error message and exit */
	if (myopcodes && myops[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", iterator,
				myopcodes);
		fclose(myfile);
		free(subjects);
		free_allstacks(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
