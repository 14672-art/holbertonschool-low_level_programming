#include "main.h"

/**
 * jack_bauer - Affiche chaque minute de la journee de Jack Bauer
 *
 * Description: Parcourt les heures de 00 a 23 et les minutes de 00 a 59
 * pour afficher le temps au format HH:MM.
 */
void jack_bauer(void)
{
	int hour, minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
			_putchar((hour / 10) + '0');
			_putchar((hour % 10) + '0');
			_putchar(':');
			_putchar((minute / 10) + '0');
			_putchar((minute % 10) + '0');
			_putchar('\n');
		}
	}
}
