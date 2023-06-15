/*
** FASTA_TOOLS PROJECT, 2023
** SBML
** File description:
** is_delim_separator
*/

#include <stdbool.h>

bool is_delim(char c, char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i]) {
            return true;
        }
    }
    return false;
}
