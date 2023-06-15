/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** requirement
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

static int count_words(char *str)
{
    int i = 0;
    int count_words = 0;

    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
        count_words++;
    }
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
            || str[i] == '\r') && str[i + 1] != '\0'
            && (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\n'
            && str[i + 1] != '\r')) {
                count_words ++;
            }
        i++;
    }
    return count_words;
}

static char *clean_loop(char *str, int nb_words)
{
    int j = 0;
    int nb_spaces = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
            && str[i] != '\r') {
            new_str[j] = str[i];
            j++;
        }
        if ((str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n'
            && str[i - 1] != '\r') && (str[i] == ' ' || str[i] == '\t'
            || str[i] == '\n' || str[i] == '\r') && nb_spaces < nb_words - 1) {
            nb_spaces++;
            new_str[j] = ' ';
            j++;
        }
    }
    return new_str;
}

char *my_strcapitalize_synthesis(char *str)
{
    int nb_words = count_words(str);

    str = clean_loop(str, nb_words);
    if (str[0] >= 'a' || str[0] >= 'z')
        str[0] = str[0] - 32;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ' && (str[i] < 'A' || str[i] > 'Z')
            && (str[i] > '9' || str[i] < '0'))
            str[i] = str[i] - 32;
    }
    return str;
}
