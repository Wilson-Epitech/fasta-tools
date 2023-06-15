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

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    char *str = NULL;
    char *buffer = malloc(sizeof(char) + 1);
    size_t length = 0;
    ssize_t nread = 0;
    char *tmp = NULL;
    int len = 0;

    *buffer = '\0';
    while ((nread = getline(&str, &length, stdin)) != -1) {
            tmp = malloc(sizeof(char) * (strlen(str)) + 1);
            sprintf(tmp, "%s", str);
            len = strlen(buffer) + strlen(str);
            buffer = realloc(buffer, len + 1);
            strcat(buffer, tmp);
            free(tmp);
    }
    fasta_loop(buffer);
    return 0;
}
