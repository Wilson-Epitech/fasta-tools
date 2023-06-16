/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** my_revstr
*/

#include <string.h>

char *my_revstr(char *str)
{
    char tmp;
    int length = strlen(str) - 1;

    for (int i = 0; i < length; i++) {
        tmp = str[i];
        str[i] = str[length];
        str[length] = tmp;
        length--;
    }
    return (str);
}
