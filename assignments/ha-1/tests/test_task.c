#include <check.h>
#include "task.h"

#ifndef COMPARATOR
#define COMPARATOR(res, c1, c2) do                      \
    {                                                   \
        char i = 0;                                     \
        for (;'\0' != (c1)[i];i++)                      \
        {                                               \
            if((c1)[i] != (c2)[i])                      \
                {                                       \
                                        (res) = 0;      \
                }                                       \
        }                                               \
    } while(0)
#endif

START_TEST (test_stub)
    {
        ck_assert(42 == stub());
    }
END_TEST

START_TEST (test_detab)
    {
        const char input_1[] = "\tabc\tdef\tghi";
        const char pattern_1[] = "    abc    def    ghi";

        const char input_2[] = "\t\t\tabc\t\t\t";
        const char pattern_2[] = "            abc            ";

        const char input_3[] = "\t abc\t  ";
        const char pattern_3[] = "     abc      ";


        char *output_1 = detab(input_1);
        char *output_2 = detab(input_2);
        char *output_3 = detab(input_3);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
        free(output_3);
    }
END_TEST

START_TEST (test_entab)
    {
        const char input_1[] = "    abc    def    ghi";
        const char pattern_1[] = "\tabc\tdef\tghi";

        const char input_2[] = "            abc            ";
        const char pattern_2[] = "\t\t\tabc\t\t\t";

        const char input_3[] = "     abc      ";
        const char pattern_3[] = "\t abc\t  ";


        char *output_1 = entab(input_1);
        char *output_2 = entab(input_2);
        char *output_3 = entab(input_3);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
        free(output_3);
    }
END_TEST

START_TEST (test_enter)
    {
        const char input_1[] = "12345 12345 12345";
        const int n_1 = 5;
        const char pattern_1[] = "12345\n12345\n12345";

        const char input_2[] = "123456 123456 123456";
        const int n_2 = 5;
        const char pattern_2[] = "123456\n123456\n123456";

        char *output_1 = enter(n_1, input_1);
        char *output_2 = enter(n_2, input_2);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);

    }
END_TEST

START_TEST (test_flush)
    {
        const char input_1[] = "//Here goes my comment line\n"
                               "\tand here is my code\n";
        const char pattern_1[] = "\tand here is my code\n";

        const char input_2[] = "/*Here goes my multiline comment\n"
                               "\t*and here the continuation\n"
                               "\tand here the end */"
                               "\tand here is my code\n";
        const char pattern_2[] = "\tand here is my code\n";

        const char input_3[] = "\tand here is my code\n";
        const char pattern_3[] = "\tand here is my code\n";


        char *output_1 = flush(input_1);
        char *output_2 = flush(input_2);
        char *output_3 = flush(input_3);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
        free(output_3);
    }
END_TEST

START_TEST (test_htoi)
    {
        const char input_1[] = "0xFF";
        const int pattern_1 = 255;

        const char input_2[] = "0XFF";
        const int pattern_2 = 255;

        const char input_3[] = "FF";
        const int pattern_3 = 255;

        const char input_4[] = "02";
        const int pattern_4 = 2;

        const char input_5[] = "0xK";
        const int pattern_5 = 0;

        const char input_6[] = "0K";
        const int pattern_6 = 0;


        int output_1 = htoi(input_1);
        int output_2 = htoi(input_2);
        int output_3 = htoi(input_3);
        int output_4 = htoi(input_4);
        int output_5 = htoi(input_5);
        int output_6 = htoi(input_6);

        ck_assert_int_eq(output_1, pattern_1);
        ck_assert_int_eq(output_2, pattern_2);
        ck_assert_int_eq(output_3, pattern_3);
        ck_assert_int_eq(output_4, pattern_4);
        ck_assert_int_eq(output_5, pattern_5);
        ck_assert_int_eq(output_6, pattern_6);
    }
END_TEST

START_TEST (test_squeeze)
    {
        const char input_1_1[] = "abcd";
        const char input_1_2[] = "ab";
        const char pattern_1[] = "cd";

        const char input_2_1[] = "aaaaaaaa";
        const char input_2_2[] = "abc";
        const char pattern_2[] = "";

        const char input_3_1[] = "abcd";
        const char input_3_2[] = "";
        const char pattern_3[] = "abcd";


        char *output_1 = squeeze(input_1_1, input_1_2);
        char *output_2 = squeeze(input_2_1, input_2_2);
        char *output_3 = squeeze(input_3_1, input_3_2);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
        free(output_3);
    }
END_TEST

START_TEST (test_any)
    {
        const char input_1_1[] = "abcd";
        const char input_1_2[] = "zzzzzd";
        const int pattern_1 = 3;

        const char input_2_1[] = "xxxxx";
        const char input_2_2[] = "ohshitwaddup";
        const int pattern_2 = -1;

        const char input_3_1[] = "smallshaq";
        const char input_3_2[] = "oneplusone";
        const int pattern_3 = 0;


        int output_1 = any(input_1_1, input_1_2);
        int output_2 = any(input_2_1, input_2_2);
        int output_3 = any(input_3_1, input_3_2);

        ck_assert_int_eq(output_1, pattern_1);
        ck_assert_int_eq(output_2, pattern_2);
        ck_assert_int_eq(output_3, pattern_3);
    }
END_TEST

START_TEST (test_binsearch_unoptimized)
    {
        int input_1[] = {1, 2, 3, 4, 5};
        const int x_1 = 3;
        const int len_1 = 5;
        const int pattern_1 = 2;

        int input_2[] = {1, 2, 4, 8, 16};
        const int x_2 = 1;
        const int len_2 = 5;
        const int pattern_2 = 0;

        int input_3[] = {1, 3, 3, 7};
        const int x_3 = 322;
        const int len_3 = 4;
        const int pattern_3 = -1;


        int output_1 = binsearch_unoptimized(x_1, input_1, len_1);
        int output_2 = binsearch_unoptimized(x_2, input_2, len_2);
        int output_3 = binsearch_unoptimized(x_3, input_3, len_3);

        ck_assert_int_eq(output_1, pattern_1);
        ck_assert_int_eq(output_2, pattern_2);
        ck_assert_int_eq(output_3, pattern_3);
    }
END_TEST

START_TEST (test_binsearch)
    {
        int input_1[] = {1, 2, 3, 4, 5};
        const int x_1 = 3;
        const int len_1 = 5;
        const int pattern_1 = 2;

        int input_2[] = {1, 2, 4, 8, 16};
        const int x_2 = 1;
        const int len_2 = 5;
        const int pattern_2 = 0;

        int input_3[] = {1, 3, 3, 7};
        const int x_3 = 322;
        const int len_3 = 4;
        const int pattern_3 = -1;


        int output_1 = binsearch(x_1, input_1, len_1);
        int output_2 = binsearch(x_2, input_2, len_2);
        int output_3 = binsearch(x_3, input_3, len_3);

        ck_assert_int_eq(output_1, pattern_1);
        ck_assert_int_eq(output_2, pattern_2);
        ck_assert_int_eq(output_3, pattern_3);
    }
END_TEST

START_TEST (test_escape)
    {
        const char input_1[] = "\t\t\thello there";
        const char pattern_1[] = "\\t\\t\\thello there";

        const char input_2[] = "\ageneral kenobi!\a";
        const char pattern_2[] = "\\ageneral kenobi!\\a";

        const char input_3[] = "swoosh";
        const char pattern_3[] = "swoosh";


        char *output_1 = escape(input_1);
        char *output_2 = escape(input_2);
        char *output_3 = escape(input_3);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
        free(output_3);
    }
END_TEST

START_TEST (test_itoa)
    {
        const int input_1 = 255;
        const char pattern_1[] = "255";

        const int input_2 = -2147483647;
        const char pattern_2[] = "-2147483647";

        const int input_3 = 0;
        const char pattern_3[] = "0";


        char *output_1 = itoa(input_1);
        char *output_2 = itoa(input_2);
        char *output_3 = itoa(input_3);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
        free(output_3);
    }
END_TEST

START_TEST (test_itob)
    {
        const int input_1_1 = 255;
        const int input_1_2 = 16;
        const char pattern_1[] = "ff";

        const int input_2_1 = -2147483647;
        const int input_2_2 = 8;
        const char pattern_2[] = "-17777777777";

        const int input_3_1 = 1337;
        const int input_3_2 = 0;
        const char pattern_3[] = "Invalid base\n";


        char *output_1 = itob(input_1_1, input_1_2);
        char *output_2 = itob(input_2_1, input_2_2);
        char *output_3 = itob(input_3_1, input_3_2);

        ck_assert_str_eq(output_1, pattern_1);
        ck_assert_str_eq(output_2, pattern_2);
        ck_assert_str_eq(output_3, pattern_3);

        free(output_1);
        free(output_2);
    }
END_TEST

START_TEST (test_strrindex)
    {
        const char input_1_1[] = "never gonna give you up";
        const char input_1_2 = 'r';
        const int pattern_1 = 4;

        const char input_2_1[] = "never gonna let you down";
        const char input_2_2 = 'n';
        const int pattern_2 = 23;

        const char input_3_1[] = "never gonna run around";
        const char input_3_2 = 'x';
        const int pattern_3 = -1;


        int output_1 = strrindex(input_1_1, input_1_2);
        int output_2 = strrindex(input_2_1, input_2_2);
        int output_3 = strrindex(input_3_1, input_3_2);

        ck_assert_int_eq(output_1, pattern_1);
        ck_assert_int_eq(output_2, pattern_2);
        ck_assert_int_eq(output_3, pattern_3);
    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_stub);

    tcase_add_test(tcase, test_detab);
    tcase_add_test(tcase, test_entab);
    tcase_add_test(tcase, test_enter);
    tcase_add_test(tcase, test_flush);
    tcase_add_test(tcase, test_htoi);
    tcase_add_test(tcase, test_squeeze);
    tcase_add_test(tcase, test_any);
    //tcase_add_test(tcase, test_setbits);
    tcase_add_test(tcase, test_binsearch_unoptimized);
    tcase_add_test(tcase, test_binsearch);
    tcase_add_test(tcase, test_escape);
    //tcase_add_test(tcase, test_expand);
    tcase_add_test(tcase, test_itoa);
    tcase_add_test(tcase, test_itob);
    tcase_add_test(tcase, test_strrindex);
    //tcase_add_test(tcase, test_atofe);

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