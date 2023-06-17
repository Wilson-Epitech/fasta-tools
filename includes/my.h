/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** my
*/

#include <stdbool.h>

#ifndef MY_H_
    #define MY_H_

    char *copy_content_file(char *file);
    int fasta_loop(int ac, char **av, char *buffer);
    int fasta_opt1(char *buffer);
    int fasta_opt2(char *buffer);
    int fasta_opt3(char *buffer);
    int fasta_opt5(char *buffer);
    int fasta_opt6(char *buffer);
    char *skip_undna_char(char *str);
    char *remove_spaces(char *str);
    char *replace_char(char *str);
    void sort_array(char **array);
    char **get_coding_sequences(char *str);
    char* get_str(char **array);

#endif /* !MY_H_ */
