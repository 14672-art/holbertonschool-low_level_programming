#include "hash_tables.h"

/**
 * hash_table_set - Ajoute ou met à jour un élément dans la table de hachage.
 * @ht: La table de hachage.
 * @key: La clé (ne peut pas être vide).
 * @value: La valeur associée (doit être dupliquée).
 *
 * Return: 1 en cas de succès, 0 sinon.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *value_copy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	/* Mise à jour de la valeur si la clé existe déjà (gestion de la collision) */
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_copy;
			return (1);
		}
	}

	/* Création d'un nouveau nœud si la clé n'existe pas */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}

	new_node->value = value_copy;
	/* Insertion en tête de liste chaînée */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
