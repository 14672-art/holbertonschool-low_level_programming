#include "hash_tables.h"

/**
 * hash_table_print - Affiche une table de hachage.
 * @ht: La table de hachage à afficher.
 *
 * Description: Affiche les couples clé/valeur dans l'ordre où ils apparaissent
 * dans le tableau, puis dans les listes chaînées.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	unsigned char flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				if (flag == 1)
					printf(", ");
				printf("'%s': '%s'", node->key, node->value);
				flag = 1;
				node = node->next;
			}
		}
	}
	printf("}\n");
}
