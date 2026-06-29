#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - Génère un nombre pseudo-aléatoire basé sur un état.
 * @state: Pointeur vers la variable d'état actuelle.
 * Return: La nouvelle valeur d'état calculée.
 */
static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return (*state);
}

/**
 * build_dataset - Remplit le tableau avec des nombres générés.
 */
static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - Effectue des opérations mathématiques sur le tableau.
 */
static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

/**
 * reduce_checksum - Calcule un checksum (empreinte numérique) du tableau.
 * Return: La valeur du checksum final.
 */
static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return (sum);
}

/**
 * main - Point d'entrée du programme, mesure le temps de chaque phase.
 * Return: Toujours 0 (Succès).
 */
int main(void)
{
    /* ================================================================= */
    /* Etape 1 : Déclaration de TOUTES les variables au début (Betty)     */
    /* ================================================================= */
    unsigned long checksum;

    /* Variables pour capturer les "ticks" d'horloge (avant/après) */
    clock_t total_start, total_end;
    clock_t build_start, build_end;
    clock_t process_start, process_end;
    clock_t reduce_start, reduce_end;

    /* Variables pour stocker le résultat final converti en secondes */
    double total_time, build_time, process_time, reduce_time;

    /* ================================================================= */
    /* Etape 2 : Placement des balises de chronométrage                  */
    /* ================================================================= */
    
    /* On démarre le chrono général immédiatement */
    total_start = clock();

    /* Mesure de la phase BUILD */
    build_start = clock();
    build_dataset();
    build_end = clock();

    /* Mesure de la phase PROCESS */
    process_start = clock();
    process_dataset();
    process_end = clock();

    /* Mesure de la phase REDUCE */
    reduce_start = clock();
    checksum = reduce_checksum();
    reduce_end = clock();

    /* On arrête le chrono général tout à la fin */
    total_end = clock();

    /* Sécurité demandée par le sujet pour éviter l'optimisation agressive */
    if (checksum == 0ul)
        printf("impossible\n");

    /* ================================================================= */
    /* Etape 3 : Calcul des durées réelles en secondes                  */
    /* ================================================================= */
    total_time   = (double)(total_end - total_start) / (double)CLOCKS_PER_SEC;
    build_time   = (double)(build_end - build_start) / (double)CLOCKS_PER_SEC;
    process_time = (double)(process_end - process_start) / (double)CLOCKS_PER_SEC;
    reduce_time  = (double)(reduce_end - reduce_start) / (double)CLOCKS_PER_SEC;

    /* ================================================================= */
    /* Etape 4 : Affichage STRICT respectant le contrat de sortie       */
    /* ================================================================= */
    printf("TOTAL seconds: %.6f\n", total_time);
    printf("BUILD_DATA seconds: %.6f\n", build_time);
    printf("PROCESS seconds: %.6f\n", process_time);
    printf("REDUCE seconds: %.6f\n", reduce_time);

    return (0);
}
