#include <stdlib.h>
typedef struct ArrayList ArrayList;
struct ArrayList {
    int *data;
    int size;
    int capacity;
};

ArrayList* arraylist(int capacity);
void alst_add(ArrayList **list, int value);
int alst_get(ArrayList *list, int index);
size_t alst_size(ArrayList *list);
void alst_rm_last(ArrayList **list);
void alst_rm_i(ArrayList **list, int index);
void alst_insert_i(ArrayList **list, int value, int index);
void alst_set(ArrayList *list, int index, int value);
void alst_clear(ArrayList **list);
void alst_check_capacity(ArrayList **list);
void alst_resize(ArrayList **list, int new_capacity);