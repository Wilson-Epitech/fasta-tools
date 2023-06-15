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

static char *skip_undna_char(char *buffer)
{
    int count = 0; int k = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 'A' || buffer[i] != 'a' || buffer[i] != 'T' ||
            buffer[i] != 't' || buffer[i] != 'G' || buffer[i] != 'g' ||
            buffer[i] != 'C' || buffer[i] != 'N' || buffer[i] != 'n')
            count ++;
    }
    char *new_buffer = malloc(sizeof(char) * (strlen(buffer - count)) + 1);
    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] == 'A' || buffer[j] == 'a' || buffer[j] == 'T'
            || buffer[j] == 't' || buffer[j] == 'G' || buffer[j] == 'g'
            || buffer[j] == 'C' || buffer[j] == 'N' || buffer[j] == 'n'
            || buffer[j] == '\n') {
                new_buffer[k] = buffer[j];
                k++;
            }
    }
    new_buffer[strlen(buffer - count + 1)] = '\0';
    return new_buffer;
}

static char *skip_lines_with_first_char(char *buffer)
{
    int count = 0;
    char **array = my_word_array_delim(buffer, "\n");
    char *new_buffer = malloc(sizeof(char) + 1);
    char *tmp = NULL;
    int len = 0;

    *new_buffer = '\0';
    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], ">", 1) != 0) {
            tmp = malloc(sizeof(char) * (strlen(array[i]) + 2));
            sprintf(tmp, "%s\n", array[i]);
            len = strlen(new_buffer) + strlen(tmp);
            new_buffer = realloc(new_buffer, len + 1);
            strcat(new_buffer, tmp);
            free(tmp);
        }
    }
    return new_buffer;
}

static char *bypass_empty_lines(char *buffer)
{
    char *tmp = NULL;
    char *new_buffer = malloc(sizeof(char) + 1);
    char **array = my_word_array_delim(buffer, "\n");
    int len = 0;

    *new_buffer = '\0';
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i] != NULL) {
            tmp = malloc(sizeof(char) * (strlen(array[i]) + 2));
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
    buffer = skip_lines_with_first_char(buffer);
    buffer = skip_undna_char(buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
            buffer[i] = buffer[i] - 32;
    }
    printf("%s\n", buffer);
    return 0;
}
