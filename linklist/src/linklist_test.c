#include<stdio.h>
#include "linklist.h"

void run_test(const char *test_name, int (*test_func)());
int assert_eq(int expected, int actual);
int assert_eq_multiple(int cases[][2], int cases_count);
int test_llst_add_node_first();
int test_llst_add_node_last();
int test_llst_get_node_first();
int test_llst_get_node_last();
int test_llst_insert_after_node();
int test_llst_insert_before_node();
int test_llst_rm_node();
int test_llst_node_at();
int test_llst_swap_nodes();
int test_llst_rm_last();
int test_llst_rm_first();
int test_llst_add_first();
int test_llst_add_last();
int test_llst_get_first();
int test_llst_get_last();
int test_llst_size();
int test_llst_insert_i();
int test_llst_rm_i();
int test_llst_set();
int test_llst_clear();
int test_llst_free();

int main()
{
    printf("Running tests...\n");
    run_test("test_llst_add_node_first", test_llst_add_node_first);
    run_test("test_llst_add_node_last", test_llst_add_node_last);
    run_test("test_llst_get_node_first", test_llst_get_node_first);
    run_test("test_llst_get_node_last", test_llst_get_node_last);
    run_test("test_llst_insert_after_node", test_llst_insert_after_node);
    run_test("test_llst_insert_before_node", test_llst_insert_before_node);
    run_test("test_llst_rm_node", test_llst_rm_node);
    run_test("test_llst_node_at", test_llst_node_at);
    run_test("test_llst_swap_nodes", test_llst_swap_nodes);
    run_test("test_llst_rm_last", test_llst_rm_last);
    run_test("test_llst_rm_first", test_llst_rm_first);
    run_test("test_llst_add_first", test_llst_add_first);
    run_test("test_llst_add_last", test_llst_add_last);
    run_test("test_llst_get_first", test_llst_get_first);
    run_test("test_llst_get_last", test_llst_get_last);
    run_test("test_llst_size", test_llst_size);
    run_test("test_llst_insert_i", test_llst_insert_i);
    run_test("test_llst_rm_i", test_llst_rm_i);
    run_test("test_llst_set", test_llst_set);
    run_test("test_llst_clear", test_llst_clear);
    run_test("test_llst_free", test_llst_free);

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

int test_llst_add_node_first() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_first(list, node);
    return assert_eq(1, llst_get_node_first(list)->data);
}

int test_llst_add_node_last() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_last(list, node);
    return assert_eq(1, llst_get_node_last(list)->data);
}

int test_llst_get_node_first() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_first(list, node);
    return assert_eq(1, llst_get_node_first(list)->data);
}

int test_llst_get_node_last() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_last(list, node);
    return assert_eq(1, llst_get_node_last(list)->data);
}

int test_llst_insert_after_node() {
    LinkedList *list = linklist();
    Node *node1 = create_node(1);
    node1->data = 1;
    Node *node2 = create_node(2);
    node2->data = 2;
    llst_add_node_first(list, node1);
    llst_insert_after_node(list, node1, node2);
    return assert_eq(2, llst_get_node_first(list)->next->data);
}

int test_llst_insert_before_node() {
    LinkedList *list = linklist();
    Node *node1 = create_node(1);
    node1->data = 1;
    Node *node2 = create_node(2);
    node2->data = 2;
    llst_add_node_first(list, node1);
    llst_insert_before_node(list, node1, node2);
    return assert_eq(2, llst_get_node_first(list)->data);
}

int test_llst_rm_node() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_first(list, node);
    llst_rm_node(list, node);
    return assert_eq(0, llst_size(list));
}

int test_llst_node_at() {
    LinkedList *list = linklist();
    Node *node1 = create_node(1);
    node1->data = 1;
    Node *node2 = create_node(2);
    node2->data = 2;
    llst_add_node_first(list, node1);
    llst_add_node_last(list, node2);
    return assert_eq(2, llst_node_at(list, 1)->data);
}

int test_llst_swap_nodes() {
    LinkedList *list = linklist();
    Node *node1 = create_node(1);
    node1->data = 1;
    Node *node2 = create_node(2);
    node2->data = 2;
    llst_add_node_first(list, node1);
    llst_add_node_last(list, node2);
    llst_swap_nodes(list, node1, node2);
    return assert_eq(2, llst_get_node_first(list)->data);
}

int test_llst_rm_last() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_first(list, node);
    llst_rm_last(list);
    return assert_eq(0, llst_size(list));
}

int test_llst_rm_first() {
    LinkedList *list = linklist();
    Node *node = create_node(1);
    node->data = 1;
    llst_add_node_first(list, node);
    llst_rm_first(list);
    return assert_eq(0, llst_size(list));
}

int test_llst_add_first() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    return assert_eq(1, llst_get_first(list));
}

int test_llst_add_last() {
    LinkedList *list = linklist();
    llst_add_last(list, 1);
    return assert_eq(1, llst_get_last(list));
}

int test_llst_get_first() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    return assert_eq(1, llst_get_first(list));
}

int test_llst_get_last() {
    LinkedList *list = linklist();
    llst_add_last(list, 1);
    return assert_eq(1, llst_get_last(list));
}

int test_llst_size() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    llst_add_last(list, 2);
    return assert_eq(2, llst_size(list));
}

int test_llst_insert_i() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    llst_add_last(list, 3);
    llst_insert_i(list, 2, 1);
    return assert_eq(2, llst_get_node_first(list)->next->data);
}

int test_llst_rm_i() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    llst_add_last(list, 3);
    llst_insert_i(list, 2, 1);
    llst_rm_i(list, 1);
    return assert_eq(2, llst_size(list));
}

int test_llst_set() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    llst_add_last(list, 3);
    llst_insert_i(list, 2, 1);
    llst_set(list, 1, 4);
    return assert_eq(4, llst_get_node_first(list)->next->data);
}

int test_llst_clear() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    llst_add_last(list, 3);
    llst_clear(list);
    int cases[3][2] = {
        {0, llst_size(list)},
        {0, llst_get_first(list)},
        {0, llst_get_last(list)}
    };
    return assert_eq_multiple(cases, 3);
}

int test_llst_free() {
    LinkedList *list = linklist();
    llst_add_first(list, 1);
    llst_add_last(list, 3);
    llst_free(list);
    return assert_eq(0, list->size);
}