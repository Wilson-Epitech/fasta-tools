/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** opt_1
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int fasta_opt1(char *buffer)
{
    char **array = my_word_array_delim(buffer, "\n");

    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], ">", 1) == 0 && i == 0) {
            printf("%s\n", array[i]);
        }
        if (strncmp(array[i], ">", 1) == 0 && i > 0) {
            printf("\n%s\n", array[i]);
        }
        if (strncmp(array[i], ">", 1) != 0) {
            array[i] = remove_spaces(array[i]);
            array[i] = skip_undna_char(array[i]);
            array[i] = my_strupcase(array[i]);
            printf("%s", array[i]);
        }
    }
    printf("\n");
    return 0;
}
