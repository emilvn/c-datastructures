#include <stdlib.h>

const int CAPACITY_LOWER_BOUND = 10;

typedef struct ArrayList ArrayList;
struct ArrayList {
    int *data;
    int size;
    int capacity;
};

// creates new ArrayList with given capacity
ArrayList* arraylist(int capacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// resizes the list to the new capacity, freeing the old data
void alst_resize(ArrayList **list, int new_capacity) {
    if(new_capacity < CAPACITY_LOWER_BOUND){
        new_capacity = CAPACITY_LOWER_BOUND;
    }
    ArrayList *new_list = arraylist(new_capacity);
    for (int i = 0; i < (*list)->size; i++) {
        new_list->data[i] = (*list)->data[i];
    }
    new_list->size = (*list)->size;
    new_list->capacity = new_capacity;
    free((*list)->data);
    free(*list);
    *list = new_list;
}

// checks if the list is full and needs to grow or under half full and can be shrunk
void alst_check_capacity(ArrayList **list) {
    if((*list)->size >= (*list)->capacity) {
        alst_resize(list, (*list)->capacity * 2);
    } else if ((*list)->size < (*list)->capacity / 2 && (*list)->capacity > CAPACITY_LOWER_BOUND) {
        alst_resize(list, (*list)->capacity / 2);
    }
}

// adds value to the end of the list
void alst_add(ArrayList **list, int value) {
    alst_check_capacity(list);
    (*list)->data[(*list)->size] = value;
    (*list)->size++;
}

// inserts value at the given index
int alst_get(ArrayList *list, int index) {
    if(index < 0 || index >= list->size) {
        return -1;
    }
    return list->data[index];
}

// gets size of the list
size_t alst_size(ArrayList *list) {
    return list->size;
}

// removes the last element from the list
void alst_rm_last(ArrayList **list) {
    (*list)->size--;
    alst_check_capacity(list);
}

// removes the element at the given index, shifting the rest of the elements
void alst_rm_i(ArrayList **list, int index) {
    // starting at index, reassigning every value to the next one
    for (int i = index; i < (*list)->size - 1; i++) {
        (*list)->data[i] = (*list)->data[i + 1];
    }
    (*list)->size--;
    alst_check_capacity(list);
}

// inserts value at the given index, pushing the rest of the elements
void alst_insert_i(ArrayList **list, int value, int index) {
    alst_check_capacity(list);
    // starting at the end of the list, reassigning every value to the previous one
    for(int i = (*list)->size; i > index; i--){
        (*list)->data[i] = (*list)->data[i - 1];
    }
    (*list)->data[index] = value;
    (*list)->size++;
}

// sets the value at the given index, overwriting the previous value
void alst_set(ArrayList *list, int index, int value) {
    list->data[index] = value;
}

// clears the list, making it empty
void alst_clear(ArrayList **list) {
    for(int i = 0; i < (*list)->size; i++){
        (*list)->data[i] = 0;
    }
    (*list)->size = 0;
    // checking capacity to shrink the list to lower bound
    alst_check_capacity(list);
}

