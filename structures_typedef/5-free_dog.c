#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees memory allocated for a dog_t structure.
 * @d: A pointer to the dog_t structure to free.
 *
 * Description: This function safely frees the strings inside the structure
 * (name and owner) before freeing the structure itself.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		/* Libération des chaînes dupliquées à l'intérieur */
		if (d->name != NULL)
			free(d->name);
		if (d->owner != NULL)
			free(d->owner);

		/* Libération de la structure globale */
		free(d);
	}
}
