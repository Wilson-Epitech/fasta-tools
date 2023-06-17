/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** my_swap_str
*/

void my_swap_str(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
