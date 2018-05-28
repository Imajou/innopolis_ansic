#include <check.h>
#include "binarize.h"

START_TEST (test_unsigned)
    {
        const long long input_1 = 9223372036854775807;
        const char pattern_1[] = "0111111111111111111111111111111111111111111111111111111111111111";

        const long long input_2 = 9223372036854775808;
        const char pattern_2[] = "00000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000";

        const long long input_3 = 18446744073709551615;
        const char pattern_3[] = "01111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";

        const long long input_4 = 1608637542;
        const char pattern_4[] = "01011111111000011101110001100110";

        char *output_1 = binarize_unsigned(input_1);
        char *output_2 = binarize_unsigned(input_2);
        char *output_3 = binarize_unsigned(input_3);
        char *output_4 = binarize_unsigned(input_4);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);
        ck_assert_str_eq(output_4, pattern_4);

        free(output_1);
        free(output_2);
        free(output_3);
        free(output_4);
    }
END_TEST

START_TEST (test_signed)
    {
        const long long input_1 = -9223372036854775804;
        const char pattern_1[] = "1000000000000000000000000000000000000000000000000000000000000100";

        const long long input_2 = -1608637542;
        const char pattern_2[] = "10100000000111100010001110011010";

        char *output_1 = binarize_signed(input_1);
        char *output_2 = binarize_signed(input_2);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);

        free(output_1);
        free(output_2);
    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Home assignment 0");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_unsigned);
    tcase_add_test(tcase, test_signed);

    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}