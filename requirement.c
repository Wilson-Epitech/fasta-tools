/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** requirement
*/

#include <stdlib.h>

char *my_strcapitalize_synthesis(char *str)
{
    if (str[0] >= 'a' || str[0] >= 'z')
        str[0] = str[0] - 32;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] = str[i] - 32;
    }
    return str;
}
