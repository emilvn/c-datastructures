#include<stdio.h>
#include "arraylist.h"

void run_test(const char *test_name, int (*test_func)());
int assert_eq(int expected, int actual);
int assert_eq_multiple(int cases[][2], int cases_count);
int test_alst_add();
int test_alst_get();
int test_alst_size();
int test_alst_rm_last();
int test_alst_rm_i();
int test_alst_insert_i();
int test_alst_set();
int test_alst_clear();
int test_alst_check_capacity();
int test_alst_resize();
int test_alst_resize_on_full();
int test_alst_resize_on_below_half_full();


int main()
{
    printf("Running tests...\n");
    run_test("test_alst_add", test_alst_add);
    run_test("test_alst_get", test_alst_get);
    run_test("test_alst_size", test_alst_size);
    run_test("test_alst_rm_last", test_alst_rm_last);
    run_test("test_alst_rm_i", test_alst_rm_i);
    run_test("test_alst_insert_i", test_alst_insert_i);
    run_test("test_alst_set", test_alst_set);
    run_test("test_alst_clear", test_alst_clear);
    run_test("test_alst_check_capacity", test_alst_check_capacity);
    run_test("test_alst_resize", test_alst_resize);
    run_test("test_alst_resize_on_full", test_alst_resize_on_full);
    run_test("test_alst_resize_on_half_full", test_alst_resize_on_below_half_full);

    return 0;
}

// mini framework
void run_test(const char *test_name, int (*test_func)()) {
    if (test_func()) {
        printf("%s: OK\n", test_name);
    } else {
        printf("%s: FAIL\n", test_name);
    }
}

int assert_eq(int expected, int actual) {
    if(expected != actual){
        printf("Expected: %d\n", expected);
        printf("Actual: %d\n", actual);
    }
    return expected == actual;
}

// accepts an array of cases, each case is an array of 2 ints in the form of {expected, actual}
int assert_eq_multiple(int cases[][2], int cases_count) {
    for (int i = 0; i < cases_count; i++) {
        if (!assert_eq(cases[i][0], cases[i][1])) {
            return 0;
        }
    }
    return 1;

}

//tests
int test_alst_add() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    int cases[4][2] = {
        {1, alst_get(list, 0)},
        {2, alst_get(list, 1)},
        {3, alst_get(list, 2)},
        {3, alst_size(list)}
    };
    return assert_eq_multiple(cases, 4);
    
}

int test_alst_get() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    return assert_eq(2, alst_get(list, 1));
}

int test_alst_size() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    return assert_eq(3, alst_size(list));
}

int test_alst_rm_last() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_rm_last(list);
    return assert_eq(2, alst_size(list));
}

int test_alst_rm_i() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_rm_i(list, 1);
    int cases[3][2] = {
        {2, alst_size(list)},
        {1, alst_get(list, 0)},
        {3, alst_get(list, 1)}
    };
    return assert_eq_multiple(cases, 3);
}

int test_alst_insert_i() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_insert_i(list, 4, 1);
    int cases[5][2] = {
        {1, alst_get(list, 0)},
        {4, alst_get(list, 1)},
        {2, alst_get(list, 2)},
        {3, alst_get(list, 3)},
        {4, alst_size(list)}
    };
    return assert_eq_multiple(cases, 5);
}

int test_alst_set() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_set(list, 1, 4);
    return assert_eq(4, alst_get(list, 1));
}

int test_alst_clear() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_clear(list);
    int cases[3][2] = {
        {0, alst_size(list)},
        {10, list->capacity},
        {-1, alst_get(list, 0)}
    };
    return assert_eq_multiple(cases, 3);
}

int test_alst_check_capacity() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_check_capacity(list);
    return assert_eq(10, list->capacity);
}

int test_alst_resize() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_resize(list, 20);
    int cases[5][2] = {
        {20, list->capacity},
        {3, list->size},
        {1, alst_get(list, 0)},
        {2, alst_get(list, 1)},
        {3, alst_get(list, 2)}
    };
    return assert_eq_multiple(cases, 5);
}

int test_alst_resize_on_full() {
    ArrayList *list = arraylist(10);
    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    alst_add(list, 4);
    alst_add(list, 5);
    alst_add(list, 6);
    alst_add(list, 7);
    alst_add(list, 8);
    alst_add(list, 9);
    alst_add(list, 10);
    alst_add(list, 11);
    alst_add(list, 12);
    int cases[3][2] = {
        {20, list->capacity},
        {12, list->size},
        {12, alst_get(list, 11)}
    };
    return assert_eq_multiple(cases, 3);
}

int test_alst_resize_on_below_half_full() {
    ArrayList *list = arraylist(20);
    alst_add(list, 1);
    int cases[3][2] = {
        {10, list->capacity},
        {1, list->size},
        {1, alst_get(list, 0)}
    };
    return assert_eq_multiple(cases, 3);
}