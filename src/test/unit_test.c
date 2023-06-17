/*
** FASTA_TOOLS PROJECT, 2023
** fasta-tools
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_delim, delim) {
    char separators[] = " ,;";
    cr_assert(is_delim(',', separators));
    cr_assert(is_delim(' ', separators));
    cr_assert(is_delim(';', separators));
}

Test(is_delim, delim2) {
    char separators[] = " ,;";
    cr_assert_not(is_delim('A', separators));
    cr_assert_not(is_delim('1', separators));
}

Test(is_number, test_number) {
    cr_assert(is_number("123"));
    cr_assert(is_number("0"));
    cr_assert(is_number("987654321"));
}

Test(is_number, test_number2) {
    cr_assert_not(is_number("abc"));
    cr_assert_not(is_number("12A34"));
    cr_assert_not(is_number("1 2 3"));
}

Test(my_revstr, test_rev2) {
    char str1[] = "XA";
    cr_assert_str_eq(my_revstr(str1), "AX");
}

Test(my_swap_str, test_swap) {
    char *str1 = "Hello";
    char *str2 = "World";
    my_swap_str(&str1, &str2);
    cr_assert_str_eq(str1, "World");
    cr_assert_str_eq(str2, "Hello");
}

Test(my_word_array_delim, test_word_array) {
    char const *str = "Hello,World!How are you?";
    char separators[] = ",! ";
    char **result = my_word_array_delim(str, separators);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert_str_eq(result[2], "How");
    cr_assert_str_eq(result[3], "are");
    cr_assert_str_eq(result[4], "you?");
    cr_assert_null(result[5]);
    print_array(result);
}

Test(fasta_loop, fast_loop_test) {
    char buffer[] = ">seq1\nATATGCAGAGTTAGT\n>seq2\nCATCATGCCTAGACGAA";
    char *argv[] = {"./FASTAtools", "1"};
    fasta_loop(2, argv, buffer);
}

Test(get_str, test_get) {
    char *array[] = {"Hello", "World", NULL};
    char *result = get_str(array);
    cr_assert_str_eq(result, "Hello\nWorld\n");
    free(result);
}

Test(fasta_opt1, fast_opt1_test) {
    char buffer[] = ">seq1\nATATGCAGAGTTAGT\n>seq2\nCATCATGCCTAGACGAA";
    fasta_opt1(buffer);
}

Test(fasta_opt2, fast_opt2_test) {
    char buffer[] = ">seq1\nATATGCAGAGTTAGT\n>seq2\nCATCATGCCTAGACGAA";
    fasta_opt1(buffer);
}

Test(fasta_opt3, fast_opt3_test) {
    char buffer[] = ">seq1\nATATGCAGAGTTAGT\n>seq2\nCATCATGCCTAGACGAA";
    fasta_opt1(buffer);
}

Test(fasta_opt5, fast_opt5_test) {
    char buffer[] = ">seq1\nATATGCAGAGTTAGT\n>seq2\nCATCATGCCTAGACGAA";
    fasta_opt1(buffer);
}

Test(replace_char, replace_char) {
    char str[] = "ATCG";
    char *result = replace_char(str);
    cr_assert_str_eq(result, "TAGC");
    free(result);
}

Test(remove_spaces, remove_spaces) {
    char str[] = "Hello World";
    char *result = remove_spaces(str);
    cr_assert_str_eq(result, "HelloWorld");
    free(result);
}

Test(skip_undna_char, skip_unDNA_characters) {
    char str[] = "ACGTNXYZ";
    char *result = skip_undna_char(str);
    cr_assert_str_eq(result, "ACGTN");
    free(result);
}

Test(sort_array, sort_array_in_alpha_order) {
    char *array[] = {"apple", "banana", "cherry", "date"};
    char *expected[] = {"apple", "banana", "cherry", "date"};

    sort_array(array);

    for (int i = 0; i < 4; i++) {
        cr_assert_str_eq(array[i], expected[i]);
    }
}

Test(sort_array, empty_array) {
    char *array[] = {};
    char *expected[] = {};

    sort_array(array);

    cr_assert_arr_eq(array, expected, 0);
}
