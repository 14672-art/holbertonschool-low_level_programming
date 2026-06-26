#include <stdio.h>

/**
 * main - Point d'entrée du programme
 *
 * Return: Toujours 0
 */
int main(void)
{
    char lettre;

    lettre = 'a';
    while (lettre <= 'z')
    {
        putchar(lettre);
        lettre++;
    }

    lettre = 'A';
    while (lettre <= 'Z')
    {
        putchar(lettre);
        lettre++;
    }

    putchar('\n');

    return (0);
}
