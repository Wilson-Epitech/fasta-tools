/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** fasta_loop
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *bypass_empty_lines(char *buffer)
{
    char *tmp = NULL;
    char *new_buffer = malloc(sizeof(char));
    char **array = my_word_array_delim(buffer, "\n");
    int len = 0;

    *new_buffer = '\0';
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i] != NULL) {
            tmp = malloc(sizeof(char) * (strlen(array[i]) + 1));
            sprintf(tmp, "%s\n", array[i]);
            len = strlen(new_buffer) + strlen(tmp) + 1;
            new_buffer = realloc(new_buffer, len);
            strcat(new_buffer, tmp);
            free(tmp);
        }
    }
    return new_buffer;
}

int fasta_loop(char *buffer)
{
    buffer = bypass_empty_lines(buffer);
    printf("%s", buffer);
    return 0;
}
