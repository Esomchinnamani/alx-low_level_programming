#include "main.h"


/**
 * Jack_Bauer - prints every minute of the day
 */
void times_table(void)
{
	int hour, minute;

	for (hour = 0; hour <=23; hour++)
	{
		for (minute = 0; minute <= 59; minute++)
		{
			_putchar((hour / 10) + '0');
			_putchar((hour % 10) + '0');
			_putchar(:);
			_putchar((minute / 10) + '0');
			_putchar((minute % 10) + '0');
			_putchar('\n);
		}
	}
}
