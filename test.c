#include "s21_string.h"

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TestData {
    char *str1;
    char *str2;
    char c;
    s21_size_t n;
} TestData;

TestData main_test_data[] = {
    {"String123", "", 'i', 1},
    {"", "ring", 'i', 1},
    {"banana", "banana", 'i', 1},
    {"", "", 'i', 1},
    {"String123", "", 'i', 10},
    {"", "ring", 'i', 10},
    {"banana", "banana", 'i', 10},
    {"", "", 'i', 10},
};

TestData *copyTestData(const TestData *src, size_t size) {
    TestData *result = malloc(size * sizeof(TestData));

    for (size_t i = 0; i < size; i++) {
        result[i].str1 = malloc(strlen(src[i].str1) + 1);
        result[i].str2 = malloc(strlen(src[i].str2) + 1);
        strcpy(result[i].str1, src[i].str1);
        strcpy(result[i].str2, src[i].str2);
        result[i].c = src[i].c;
        result[i].n = src[i].n;
    }
    return result;
}

void freeTestData(TestData *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        free(data[i].str1);
        free(data[i].str2);
    }
    free(data);
}

START_TEST(memchr_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_ptr_eq(s21_memchr(test.str1, test.c, test.n), memchr(test.str1, test.c, test.n));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(memcmp_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_int_eq(s21_memcmp(test.str1, test.str2, test.n), memcmp(test.str1, test.str2, test.n));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(memcpy_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        char *s21_buffer = malloc(test.n + 1);
        char *std_buffer = malloc(test.n + 1);
        memset(s21_buffer, 0, test.n + 1);
        memset(std_buffer, 0, test.n + 1);
        s21_memcpy(s21_buffer, test.str1, test.n);
        memcpy(std_buffer, test.str1, test.n);

        ck_assert_mem_eq(s21_buffer, std_buffer, test.n);

        free(s21_buffer);
        free(std_buffer);
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(memset_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        char *s21_buffer = malloc(test.n + 1);
        char *std_buffer = malloc(test.n + 1);
        memcpy(s21_buffer, test.str1, test.n);
        memcpy(std_buffer, test.str1, test.n);
        s21_memset(s21_buffer, test.c, test.n);
        memset(std_buffer, test.c, test.n);

        ck_assert_mem_eq(s21_buffer, std_buffer, test.n);

        free(s21_buffer);
        free(std_buffer);
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strncat_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        size_t dest_len = strlen(test.str1);
        size_t src_len = strlen(test.str2);
        size_t buffer_size = dest_len + src_len + 1;
        char *s21_buffer = malloc(buffer_size);
        char *std_buffer = malloc(buffer_size);
        strcpy(s21_buffer, test.str1);
        strcpy(std_buffer, test.str1);
        s21_strncat(s21_buffer, test.str2, test.n);
        strncat(std_buffer, test.str2, test.n);
        ck_assert_str_eq(s21_buffer, std_buffer);
        free(s21_buffer);
        free(std_buffer);
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strchr_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_ptr_eq(s21_strchr(test.str1, test.c), strchr(test.str1, test.c));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strncmp_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_int_eq(s21_strncmp(test.str1, test.str2, test.n), strncmp(test.str1, test.str2, test.n));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strncpy_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        char *s21_buffer = malloc(test.n + 1);
        char *std_buffer = malloc(test.n + 1);
        memset(s21_buffer, 0, test.n + 1);
        memset(std_buffer, 0, test.n + 1);
        s21_strncpy(s21_buffer, test.str1, test.n);
        strncpy(std_buffer, test.str1, test.n);

        ck_assert_str_eq(s21_buffer, std_buffer);

        free(s21_buffer);
        free(std_buffer);
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strcspn_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_int_eq(s21_strcspn(test.str1, test.str2), strcspn(test.str1, test.str2));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strerror_test) {
    for (size_t i = 0; i < 150; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(strlen_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_uint_eq(s21_strlen(test.str1), strlen(test.str1));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strpbrk_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_ptr_eq(s21_strpbrk(test.str1, test.str2), strpbrk(test.str1, test.str2));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strrchr_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_ptr_eq(s21_strrchr(test.str1, test.c), strrchr(test.str1, test.c));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(strstr_test) {
    size_t data_size = sizeof(main_test_data) / sizeof(TestData);
    TestData *test_data = copyTestData(main_test_data, data_size);
    for (size_t i = 0; i < data_size; i++) {
        TestData test = test_data[i];
        ck_assert_ptr_eq(s21_strstr(test.str1, test.str2), strstr(test.str1, test.str2));
    }
    freeTestData(test_data, data_size);
}
END_TEST

START_TEST(sprintf_test) {
    typedef struct SprintfData {
        int number;
        long int long_number;
        unsigned int u_number;
        unsigned long int u_long_number;
        double d_number;
        char c;
        char *str;
    } SprintfData;

    SprintfData data[] = {
        {12345, 456456011, 5635634, 645234355, 123.33303, 'i', "some_string"},
        {12345, 456456011, 5635634, 645234355, 123, 'K', "some_string"},
        {-123456, 456456011, 5635634, 645234355, 123.33303, '7', "some_string"},
        {12345, -456456011, 5635634, 645234355, 123.33303, 'T', "some_string"},
        {0, 0, 0, 0, 0, '0', "some_string"},
        {-123, 4-56456011, 5635634, 645234355, 123.1610005, 'F', "some_string"},
    };

    char *s21_buffer = malloc(128 * sizeof(char));
    char *buffer = malloc(128 * sizeof(char));
    size_t data_size = sizeof(data) / sizeof(SprintfData);
    for (size_t i = 0; i < data_size; i++) {
        SprintfData test_data = data[i];

        s21_sprintf(s21_buffer, "q% 2.5d %2.5sG", test_data.number, test_data.str);
        sprintf(buffer, "q% 2.5d %2.5sG", test_data.number, test_data.str);
        ck_assert_str_eq(s21_buffer, buffer);

        s21_sprintf(s21_buffer, "q%5c %-2.5s %-5.3d %%G", test_data.c, test_data.str, test_data.number);
        sprintf(buffer, "q%5c %-2.5s %-5.3d %%G", test_data.c, test_data.str, test_data.number);
        ck_assert_str_eq(s21_buffer, buffer);

        s21_sprintf(s21_buffer, "k %lu %-2.3u", test_data.u_long_number, test_data.u_number);
        sprintf(buffer, "k %lu %-2.3u", test_data.u_long_number, test_data.u_number );
        ck_assert_str_eq(s21_buffer, buffer);
    }

    free(s21_buffer);
    free(buffer);
}
END_TEST

Suite *create_string_suite(void) {
    Suite *suite = suite_create("string_suite");
    TCase *test_case = tcase_create("string_test_case");

    tcase_add_test(test_case, memchr_test);
    tcase_add_test(test_case, memcmp_test);
    tcase_add_test(test_case, memcpy_test);
    tcase_add_test(test_case, memset_test);
    tcase_add_test(test_case, strncat_test);
    tcase_add_test(test_case, strchr_test);
    tcase_add_test(test_case, strncmp_test);
    tcase_add_test(test_case, strncpy_test);
    tcase_add_test(test_case, strcspn_test);
    tcase_add_test(test_case, strerror_test);
    tcase_add_test(test_case, strlen_test);
    tcase_add_test(test_case, strpbrk_test);
    tcase_add_test(test_case, strrchr_test);
    tcase_add_test(test_case, strstr_test);
    tcase_add_test(test_case, sprintf_test);

    suite_add_tcase(suite, test_case);
    return suite;
}

int main(void) {
    SRunner *runner = srunner_create(create_string_suite());
    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? 0 : 1;
}
