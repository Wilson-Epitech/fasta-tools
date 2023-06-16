/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** remove_spaces
*/

#include <stdlib.h>
#include <string.h>

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
