/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac < 4)
        return 84;
    char *buffer = copy_content_file(av[3]);
    fasta_loop(buffer);
    return 0;
}
