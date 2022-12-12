#include <stdio.h>
/**
 * main - Entry point
 *
 * return: Always 0 (success)
 */

int main(void)
{
	int a;

	for (a = 0; a < 10; a++)
	{
		putchar(a + '0');
		if (a < 9)
		{
			putchar(',');
			putchar(' ');
	a++;
		}
	}
	putchar('\n');
	return (0);
}
