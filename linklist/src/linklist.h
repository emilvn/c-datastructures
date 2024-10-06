#include <stdlib.h>
#ifndef LINKLIST_H
#define LINKLIST_H
typedef struct Node Node;
struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    Node *head;
    Node *tail;
    size_t size;
};

LinkedList* linklist();
void llst_add_node_first(LinkedList *list, Node *node);
void llst_add_node_last(LinkedList *list, Node *node);
Node* llst_get_node_first(LinkedList *list);
Node* llst_get_node_last(LinkedList *list);
void llst_insert_after_node(LinkedList *list, Node *existing_node, Node *new_node);
void llst_insert_before_node(LinkedList *list, Node *existing_node, Node *new_node);
void llst_rm_node(LinkedList *list, Node *node);
Node* llst_node_at(LinkedList *list, int index);
void llst_swap_nodes(LinkedList *list, Node *node1, Node *node2);

void llst_rm_last(LinkedList *list);
void llst_rm_first(LinkedList *list);
void llst_add_first(LinkedList *list, int value);
void llst_add_last(LinkedList *list, int value);
int llst_get_first(LinkedList *list);
int llst_get_last(LinkedList *list);
size_t llst_size(LinkedList *list);
void llst_insert_i(LinkedList *list, int value, int index);
void llst_rm_i(LinkedList *list, int index);
void llst_set(LinkedList *list, int index, int value);
void llst_clear(LinkedList *list);
void llst_free(LinkedList *list);
#endif