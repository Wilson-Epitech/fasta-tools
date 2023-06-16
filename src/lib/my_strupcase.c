/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** my_str_upcase
*/

#include <string.h>
#include <stdlib.h>

char *my_strupcase(char *str)
{
    int len = strlen(str);
    char *new_str = malloc(sizeof(char) * (len) + 1);

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
