#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

// creates new LinkedList
LinkedList* linklist() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        fprintf(stderr, "memory allocation failed for LinkedList\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// creates new Node
Node* create_node(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// adds node to the beginning of the list
void llst_add_node_first(LinkedList *list, Node *node) {
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}

// adds node to the end of the list
void llst_add_node_last(LinkedList *list, Node *node) {
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// gets the first node of the list
Node* llst_get_node_first(LinkedList *list) {
    return list->head;
}

// gets the last node of the list
Node* llst_get_node_last(LinkedList *list) {
    return list->tail;
}

// inserts new_node after existing_node
void llst_insert_after_node(LinkedList *list, Node *existing_node, Node *new_node) {
    new_node->next = existing_node->next;
    new_node->prev = existing_node;
    existing_node->next = new_node;
    if (new_node->next) {
        new_node->next->prev = new_node;
    } else {
        list->tail = new_node;
    }
    list->size++;
}

// inserts new_node before existing_node
void llst_insert_before_node(LinkedList *list, Node *existing_node, Node *new_node) {
    new_node->next = existing_node;
    new_node->prev = existing_node->prev;
    existing_node->prev = new_node;
    if (new_node->prev) {
        new_node->prev->next = new_node;
    } else {
        list->head = new_node;
    }
    list->size++;
}

// removes node from the list
void llst_rm_node(LinkedList *list, Node *node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    free(node);
    list->size--;
}

// gets node at the given index
Node* llst_node_at(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    Node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

// swaps node1 with node2, just swap data
void llst_swap_nodes(LinkedList *list, Node *node1, Node *node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// removes the last node from the list
void llst_rm_last(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *node = list->tail;
    list->tail = node->prev;
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(node);
    list->size--;
}

// removes the first node from the list
void llst_rm_first(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *node = list->head;
    list->head = node->next;
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(node);
    list->size--;
}

// adds value to the beginning of the list
void llst_add_first(LinkedList *list, int value) {
    Node *node = create_node(value);
    if (!node) {
        fprintf(stderr, "memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = list->head;
    if (list->size == 0) {
        list->tail = node;
    } else {
        list->head->prev = node;
    }
    list->head = node;
    list->size++;
}

// adds value to the end of the list
void llst_add_last(LinkedList *list, int value) {
    Node *node = create_node(value);
    if (!node) {
        fprintf(stderr, "memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->prev = list->tail;
    if (list->size == 0) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

// gets the value of the first node
int llst_get_first(LinkedList *list) {
    if(list->size == 0) {
        return 0;
    }
    return list->head->data;
}

// gets the value of the last node
int llst_get_last(LinkedList *list) {
    if(list->size == 0) {
        return 0;
    }
    return list->tail->data;
}

// gets the size of the list
size_t llst_size(LinkedList *list) {
    return list->size;
}

// inserts value at the given index
void llst_insert_i(LinkedList *list, int value, int index) {
    if (index < 0 || index > list->size) {
        return;
    }
    if (index == 0) {
        llst_add_first(list, value);
        return;
    }
    if (index == list->size) {
        llst_add_last(list, value);
        return;
    }
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    Node *existing_node = llst_node_at(list, index);
    llst_insert_before_node(list, existing_node, node);
}

// removes node at the given index
void llst_rm_i(LinkedList *list, int index) {
    Node *node = llst_node_at(list, index);
    if (node) {
        llst_rm_node(list, node);
    }
}

// sets the value of the node at the given index
void llst_set(LinkedList *list, int index, int value) {
    Node *node = llst_node_at(list, index);
    if (node) {
        node->data = value;
    }
}

// clears the list
void llst_clear(LinkedList *list) {
    while (list->size > 0) {
        llst_rm_last(list);
    }
}

// frees the list and all nodes
void llst_free(LinkedList *list) {
    llst_clear(list);
    free(list);
}
