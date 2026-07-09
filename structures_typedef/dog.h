#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A struct that stores basic information about a dog.
 * @name: Pointer to a char array representing the dog's name.
 * @age: Float representing the dog's age.
 * @owner: Pointer to a char array representing the owner's name.
 *
 * Description: This structure groups the essential attributes of a dog,
 * including its identity, age, and who it belongs to.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
