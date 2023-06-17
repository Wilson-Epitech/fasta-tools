/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** opt_5_2
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"
#include "my.h"

int find_index(char *str, int start)
{
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == 'A' && str[i + 1] == 'T' && str[i + 2] == 'G') {
            return i;
        }
    }
    return -1;
}

char *extract_sequence(char *str, int start, int end)
{
    int seq_len = end - start + 1;
    char *new_str = malloc(sizeof(char) * (seq_len + 1));
    strncpy(new_str, str + start, seq_len);
    new_str[seq_len] = '\0';
    return new_str;
}

int find_end_index(char *str, int start)
{
    int len = strlen(str);
    for (int j = start + 3; j < len - 2; j += 3) {
        if ((str[j] == 'T' && str[j + 1] == 'A' && str[j + 2] == 'A') ||
            (str[j] == 'T' && str[j + 1] == 'A' && str[j + 2] == 'G') ||
            (str[j] == 'T' && str[j + 1] == 'G' && str[j + 2] == 'A')) {
            return j - 1;
        }
    }
    return -1;
}

char **get_coding_sequences(char *str)
{
    int len = strlen(str);
    char **array = malloc(sizeof(char *) * len);
    int count = 0; int i = 0;

    while (i < len) {
        int start = find_index(str, i);
        if (start == -1)
            break;
        int end = find_end_index(str, start);
        if (end != -1) {
            char *new_str = extract_sequence(str, start, end);
            array[count++] = new_str;
            i = end + 4;
        } else {
            i = start + 1;
        }
    }
    array[count] = NULL;
    sort_array(array);
    return array;
}
