/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** print_array
*/

#include <stdio.h>
#include <stdlib.h>

void print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s", array[i]);
    }
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
