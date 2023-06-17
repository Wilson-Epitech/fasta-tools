/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** skip_undna_char
*/

#include <string.h>
#include <stdlib.h>

char *skip_undna_char(char *str)
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
    new_str[k] = '\0';
    return new_str;
}
