/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** is_number
*/

#include <stdbool.h>

bool is_number(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
