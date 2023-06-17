/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** lib
*/

#include <stdbool.h>

#ifndef LIB_H_
    #define LIB_H_

    bool is_delim(char c, char *separators);
    char **my_word_array_delim(char const *str, char *separators);
    bool is_number(char const *str);
    char *my_strupcase(char *str);
    char *my_revstr(char *str);
    void print_array(char **array);
    void my_swap_str(char **a, char **b);

#endif /* !LIB_H_ */
