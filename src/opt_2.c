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

static char *replace_char_by_char(char *str, char find, char replace)
{
    int k = 0;
    char *new_str = NULL;
    int len = strlen(str);
    new_str = malloc(sizeof(char) * (len) + 1);

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == find) {
            new_str[k] = replace;
            k++;
        } else {
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
            array[i] = replace_char_by_char(array[i], 'T', 'U');
            printf("%s", array[i]);
        }
    }
    printf("\n");
    return 0;
}
