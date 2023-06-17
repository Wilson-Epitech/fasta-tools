/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** sort_array
*/

#include <stdlib.h>
#include <string.h>
#include "lib.h"

int sort_array_2(char **array, int len, int i)
{
    for (int j = i + 1; j < len; j++) {
        if (strcmp(array[i], array[j]) > 0) {
            my_swap_str(&array[i], &array[j]);
        }
    }
    return i;
}

void sort_array(char **array)
{
    int len = 0;
    while (array[len] != NULL) {
        len++;
    }

    for (int i = 0; i < len - 1; i++) {
        i = sort_array_2(array, len, i);
    }
}
