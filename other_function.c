#include "monty.h"

/**
* space_check - checks if get_line string contains spaces
*
* @get_line_string: string to check
*
* Return: 0
*/
int space_check(char *get_line_string)
{
	int i;

	for (i = 0; get_line_string[i]; i++)
	{
		if (isspace(get_line_string[i]) == 0)
			return (-1);
	}
	return (0);
}
