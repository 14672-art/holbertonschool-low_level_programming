#include "main.h"
#include <stdlib.h>

/**
 * create_array - Crée un tableau de char et l'initialise avec un char précis.
 * @size: La taille du tableau à allouer.
 * @c: Le caractère d'initialisation.
 *
 * Return: Un pointeur vers le tableau, ou NULL en cas d'échec ou si size = 0.
 */
char *create_array(unsigned int size, char c)
{
    char *array;
    unsigned int i;

    /* Étape A : Vérification si la taille est à 0 */
    if (size == 0)
    {
        return (NULL);
    }

    /* Étape B : Allocation dynamique de la mémoire */
    array = malloc(sizeof(char) * size);

    /* Vérification du succès de malloc */
    if (array == NULL)
    {
        return (NULL);
    }

    /* Étape C : Remplissage du tableau */
    i = 0;
    while (i < size)
    {
        array[i] = c;
        i++;
    }

    /* Étape D : Retour du pointeur */
    return (array);
}
