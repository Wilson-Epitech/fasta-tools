/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** fasta_loop
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>

int fasta_loop(int ac, char **av, char *buffer)
{
    int opt_value = atoi(av[1]);
    if (ac == 2 && is_number(av[1]) && opt_value == 1)
        fasta_opt1(buffer);
    if (ac == 2 && is_number(av[1]) && opt_value == 2)
        fasta_opt2(buffer);
    return 0;
}
