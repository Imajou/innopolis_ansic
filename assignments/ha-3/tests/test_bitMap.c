#include <check.h>
#include <stdlib.h>
#include <printf.h>
#include <bitMap.h>

START_TEST (test_setBitByNumber)
    {
        int *ptr = malloc(8 * sizeof(int));
        for (int i = 0; i < 8; ++i) {
            ptr[i] = 0;
        }
        for (int j = 0; j < 8; ++j) {
            printf("%d", ptr[j]);
        }
        setBitByNumber(ptr, 1, 0);
        setBitByNumber(ptr, 1, 1);
        setBitByNumber(ptr, 1, 2);
        setBitByNumber(ptr, 1, 3);

        ck_assert_int_eq(getBitByNumber(ptr, 0), 1);
        ck_assert_int_eq(getBitByNumber(ptr, 1), 1);
        ck_assert_int_eq(getBitByNumber(ptr, 2), 1);
        ck_assert_int_eq(getBitByNumber(ptr, 3), 1);

        ck_assert_int_eq(getBitByNumber(ptr, 4), 0);
    }
END_TEST

START_TEST (test_getBitByNumber)
    {
        unsigned int *ptr = malloc(8 * sizeof(int));
        for (int i = 0; i < 8; ++i) {
            ptr[i] = 0;
        }
        for (int j = 0; j < 8; ++j) {
            printf("%d", ptr[j]);
        }
        ptr[0] = 0xF0000000;

        ck_assert_int_eq(getBitByNumber(ptr, 0), 1);
        ck_assert_int_eq(getBitByNumber(ptr, 1), 1);
        ck_assert_int_eq(getBitByNumber(ptr, 2), 1);
        ck_assert_int_eq(getBitByNumber(ptr, 3), 1);

        ck_assert_int_eq(getBitByNumber(ptr, 4), 0);

    }
END_TEST

START_TEST (test_setBitByAddress)
    {
        int *ptr = malloc(8 * sizeof(int));
        for (int i = 0; i < 8; ++i) {
            ptr[i] = 0;
        }
        for (int j = 0; j < 8; ++j) {
            printf("%d", ptr[j]);
        }
        setBitByAddress(ptr, 1);
        ck_assert_int_eq(ptr[0], INT32_MIN);
    }
END_TEST

START_TEST (test_getBitByAddress)
    {
        unsigned int *ptr = malloc(8 * sizeof(int));
        for (int i = 0; i < 8; ++i) {
            ptr[i] = 0;
        }
        for (int j = 0; j < 8; ++j) {
            printf("%d", ptr[j]);
        }
        ptr[0] = 0xF0000000;
        ptr[1] = 0xF0000000;

        ck_assert_int_eq(getBitByAddress(ptr), 1);
        ck_assert_int_eq(getBitByAddress(ptr + 1), 1);
        ck_assert_int_eq(getBitByAddress(ptr + 2), 0);
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("Bit Map");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_setBitByNumber);
    tcase_add_test(tcase, test_getBitByNumber);
    tcase_add_test(tcase, test_setBitByAddress);
    tcase_add_test(tcase, test_getBitByAddress);

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