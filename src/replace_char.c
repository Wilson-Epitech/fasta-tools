/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** replace_char
*/

#include <stdlib.h>
#include <string.h>

static int replace_char2(char *str, char *new_str, int k, int j)
{
    if (str[j] == 'T') {
            new_str[k] = 'A';
            k++;
    }
    if (str[j] == 'A') {
        new_str[k] = 'T';
        k++;
    }
    if (str[j] == 'C') {
        new_str[k] = 'G';
        k++;
    }
    if (str[j] == 'G') {
        new_str[k] = 'C';
        k++;
    }
    if (str[j] != 'G' && str[j] != 'A' && str[j] != 'T' && str[j] != 'C') {
        new_str[k] = str[j];
        k++;
    } return k;
}

char *replace_char(char *str)
{
    int k = 0;
    char *new_str = NULL;
    int len = strlen(str);
    new_str = malloc(sizeof(char) * (len) + 1);

    for (int j = 0; str[j] != '\0'; j++) {
        k = replace_char2(str, new_str, k, j);
    }
    return new_str;
}
