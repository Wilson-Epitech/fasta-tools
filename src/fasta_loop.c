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
            || buffer[j] != '\n') {
                new_buffer[k] = buffer[j];
                k++;
            }
    }
    return new_buffer;
}

static char *bypass_empty_lines(char *buffer)
{
    printf("%s", buffer);
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

char *remove_spaces(char *str)
{
    int k = 0;
    int count = 0;
    char *new_str = NULL;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count ++;
    }
    len = strlen(str) - count + 2;
    new_str = malloc(sizeof(char) * (len));
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] != ' ') {
            new_str[k] = str[j];
            k++;
        }
    }
    return new_str;
}

char *my_strupcase(char *str)
{
    int len = strlen(str) + 1;
    char *new_str = malloc(sizeof(char) * (len));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            new_str[i] = str[i] - 32;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
            new_str[i] = str[i];
    }
    new_str[len] = '\0';
    return new_str;
}

int fasta_loop(char *buffer)
{
    char **array = NULL;
    array = my_word_array_delim(buffer, "\n");

    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], ">", 1) != 0) {
            array[i] = remove_spaces(array[i]);
            array[i] = my_strupcase(array[i]);
        }
        printf("%s\n", array[i]);
    }
    return 0;
}
