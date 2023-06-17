/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** main
*/

#include "my.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int error_handling(int ac, char **av)
{
    int nb = 0;
    if (ac == 3 && (is_number(av[1])))
        nb = atoi(av[1]);
    if (nb > 7 || nb < 1)
        return 84;
    if (ac == 3 && nb != 4)
        return 84;
    if (ac == 3 && (!is_number(av[1]) || (!is_number(av[2]))))
        return 84;
    if (ac < 2)
        return 84;
    if (ac == 2 && !is_number(av[1]))
        return 84;
    if (ac > 3)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    char *str = NULL;
    char *buffer = malloc(sizeof(char) + 1);
    size_t length = 0;
    ssize_t nread = 0;
    char *tmp = NULL;
    int len = 0;

    if (error_handling(ac, av) == 84)
        return 84;
    *buffer = '\0';
    while ((nread = getline(&str, &length, stdin)) != -1) {
            tmp = malloc(sizeof(char) * (strlen(str)) + 1);
            sprintf(tmp, "%s", str);
            len = strlen(buffer) + strlen(str);
            buffer = realloc(buffer, len + 1);
            strcat(buffer, tmp);
            free(tmp);
    }
    fasta_loop(ac, av, buffer);
    return 0;
}
