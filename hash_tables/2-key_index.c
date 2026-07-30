#include "hash_tables.h"

/**
 * key_index - Donne l'index d'une clé dans le tableau de la table de hachage.
 * @key: La clé à hacher.
 * @size: La taille du tableau de la table de hachage.
 *
 * Return: L'index où le couple clé/valeur doit être stocké.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

