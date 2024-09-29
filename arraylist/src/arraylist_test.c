#include<stdio.h>
#include "arraylist.h"

void run_test(const char *test_name, int (*test_func)());
int assert_eq(int expected, int actual);
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

//tests
int test_alst_add() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    return assert_eq(3, alst_get(list, 2));
}

int test_alst_get() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    return assert_eq(2, alst_get(list, 1));
}

int test_alst_size() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    return assert_eq(3, alst_size(list));
}

int test_alst_rm_last() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_rm_last(&list);
    return assert_eq(2, alst_size(list));
}

int test_alst_rm_i() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_rm_i(&list, 1);
    return assert_eq(2, alst_size(list));
}

int test_alst_insert_i() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_insert_i(&list, 4, 1);
    return assert_eq(4, alst_get(list, 1));
}

int test_alst_set() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_set(list, 1, 4);
    return assert_eq(4, alst_get(list, 1));
}

int test_alst_clear() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_clear(&list);
    return assert_eq(0, alst_size(list));
}

int test_alst_check_capacity() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_check_capacity(&list);
    return assert_eq(10, list->capacity);
}

int test_alst_resize() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_resize(&list, 20);
    return assert_eq(20, list->capacity);
}

int test_alst_resize_on_full() {
    ArrayList *list = arraylist(10);
    alst_add(&list, 1);
    alst_add(&list, 2);
    alst_add(&list, 3);
    alst_add(&list, 4);
    alst_add(&list, 5);
    alst_add(&list, 6);
    alst_add(&list, 7);
    alst_add(&list, 8);
    alst_add(&list, 9);
    alst_add(&list, 10);
    alst_add(&list, 11);
    alst_add(&list, 12);
    return assert_eq(20, list->capacity);
}

int test_alst_resize_on_below_half_full() {
    ArrayList *list = arraylist(20);
    alst_add(&list, 1);
    return assert_eq(10, list->capacity);
}