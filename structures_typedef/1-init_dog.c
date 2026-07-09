#include "dog.h"
#include <stddef.h>

/**
 * init_dog - Initializes a variable of type struct dog.
 * @d: A pointer to the struct dog to initialize.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Description: This function assigns the provided name, age, and owner
 * to the elements of the struct dog pointed to by d.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
