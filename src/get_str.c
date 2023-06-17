/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** get_str
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* get_str(char **array)
{
    int len = 0;
    int position = 0;
    char* new_str = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        len += strlen(array[i]) + 1;
    }
    new_str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; array[i] != NULL; i++) {
        position += sprintf(new_str + position, "%s\n", array[i]);
    }
    return new_str;
}
