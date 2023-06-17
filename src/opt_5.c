/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** opt_4
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *get_name_seq(char *str, char *new_buffer, char *tmp, int len)
{
    tmp = malloc(sizeof(char) * (strlen(str) + 3));
    sprintf(tmp, "\n%s\n", str);
    len = strlen(new_buffer) + strlen(str);
    new_buffer = realloc(new_buffer, len + 3);
    strcat(new_buffer, tmp);
    free(tmp);
    return new_buffer;
}

static char *get_first_line(char *str, char *new_buffer, char *tmp, int len)
{
    tmp = malloc(sizeof(char) * (strlen(str)) + 2);
    sprintf(tmp, "%s\n", str);
    len = strlen(new_buffer) + strlen(str);
    new_buffer = realloc(new_buffer, len + 2);
    strcat(new_buffer, tmp);
    free(tmp);
    return new_buffer;
}

static char *get_group_str(char *str, char *new_buffer, char *tmp, int len)
{
    tmp = malloc(sizeof(char) * (strlen(str)) + 2);
    str = remove_spaces(str);
    str = skip_undna_char(str);
    str = my_strupcase(str);
    sprintf(tmp, "%s", str);
    len = strlen(new_buffer) + strlen(str);
    new_buffer = realloc(new_buffer, len + 1);
    strcat(new_buffer, tmp);
    free(tmp);
    return new_buffer;
}

static char *get_valid_buffer(char *buffer)
{
    char **array = my_word_array_delim(buffer, "\n");
    char *new_buffer = malloc(sizeof(char));
    char *tmp = NULL;
    int len = 0;

    *new_buffer = '\0';
    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], ">", 1) == 0 && i == 0) {
            new_buffer = get_first_line(array[i], new_buffer, tmp, len);
        }
        if (strncmp(array[i], ">", 1) == 0 && i > 0) {
            new_buffer = get_name_seq(array[i], new_buffer, tmp, len);
        }
        if (strncmp(array[i], ">", 1) != 0) {
            new_buffer = get_group_str(array[i], new_buffer, tmp, len);
        }
    }
    return new_buffer;
}

int fasta_opt5(char *buffer)
{
    char **array = NULL;
    char **new_array = NULL;
    buffer = get_valid_buffer(buffer);
    array = my_word_array_delim(buffer, "\n");
    char** new_buffer = NULL;
    int count = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], ">", 1) != 0) {
            new_array = get_coding_sequences(array[i]);
            char* output = get_str(new_array);
            new_buffer = realloc(new_buffer, sizeof(char*) * (count + 1));
            new_buffer[count++] = output;
        }
    }
    sort_array(new_buffer);
    print_array(new_buffer);
    return 0;
}
