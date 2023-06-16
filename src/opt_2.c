/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** opt_2
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *replace_char_by_char(char *str, char c)
{
    int k = 0;
    char *new_str = NULL;
    int len = strlen(str);
    new_str = malloc(sizeof(char) * (len) + 1);

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == 'T') {
            new_str[k] = c;
            k++;
        } else {
            new_str[k] = str[j];
            k++;
        }
    }
    return new_str;
}

static char *skip_undna_char(char *str)
{
    int k = 0;
    int len = strlen(str) + 1;
    char *new_str = malloc(sizeof(char) * (len) + 1);

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == 'A' || str[j] == 'a' || str[j] == 'T'
            || str[j] == 't' || str[j] == 'G' || str[j] == 'g'
            || str[j] == 'C' || str[j] == 'N' || str[j] == 'n'
            || str[j] == 'c' || str[j] == '\n') {
                new_str[k] = str[j];
                k++;
        }
    }
    return new_str;
}

static char *remove_spaces(char *str)
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

int fasta_opt2(char *buffer)
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
            array[i] = replace_char_by_char(array[i], 'U');
            printf("%s", array[i]);
        }
    }
    return 0;
}
