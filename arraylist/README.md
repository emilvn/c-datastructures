# Arraylist datastructure

to build

```bash
./build.bash
```

to build and run

```bash
./run.bash
```

## ArrayList properties:

- **size**: number of elements in the list
- **capacity**: number of elements the list can hold
- **data**: pointer to the first element in the list

## ArrayList functions:

### Public functions:

- **arraylist(int capacity)**: constructor, creates a new list with the given capacity, and returns a pointer to the list
- **alst_add(ArrayList \*list, int value)**: adds a new element to the end of the list
- **alst_get(ArrayList \*list, int index)**: returns the element at the given index
- **alst_size(ArrayList \*list)**: returns the number of elements in the list(size)
- **alst_rm_last(ArrayList \*list)**: removes the last element in the list
- **alst_rm_i(ArrayList \*list, int index)**: removes the element at the given index
- **alst_insert_i(ArrayList \*list, int value, int index)**: inserts a new element at the given index
- **alst_set(ArrayList \*list, int index, int value)**: sets the element at the given index to the given value
- **alst_clear(ArrayList \*list)**: removes all elements from the list

### Private/Internal helper functions:

- **alst_check_capacity(ArrayList \*list)**: checks if the list needs to be resized, and calls alst_resize if the list is full or less than 1/2 full.
- a**lst_resize(ArrayList \*list, int new_capacity)**: resizes the list to the given capacity or the constant lower bound of 10.

### Example:

```c
#include "arraylist.h"

int main()
{
    // Create a new list with a capacity of 10
    ArrayList *list = arraylist(10);

    // Add elements to the list
    alst_add(list, 1);
    alst_add(list, 2);

    // Get the element at index 1
    alst_get(list, 1); // returns 2

    // Get the number of elements in the list
    alst_size(list); // returns 2

    // Remove the last element in the list
    alst_rm_last(list);

    // Remove the element at index 0
    alst_rm_i(list, 0);

    // Insert a new element at index 0
    alst_insert_i(list, 3, 0);

    // Set the element at index 0 to 4
    alst_set(list, 0, 4);

    // Clear the list
    alst_clear(list);

    return 0;
}
```
