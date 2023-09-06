#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { max, min };

#define get_parent_index(idx) ((idx-1)/2)
#define compare(type, val_1, val_2) ((type == max) ? ((val_1 > val_2) ? 1 : 0) : ((val_1 < val_2) ? 1 : 0))

typedef struct heap {

    int size;
    int max_size;
    int* arr;
    int type;

}heap;

void init_heap(heap* _heap, int _type) {
    _heap->size = 0;
    _heap->max_size = 10;
    _heap->arr = (int*)calloc(10, sizeof(int));
    _heap->type = _type;
}

void destory_heap(heap* _heap) {
    free(_heap->arr);
}

int get_left_child_index(heap* _heap, int idx) {
    return (((idx * 2) + 1) < _heap->size) ? (idx * 2) + 1 : -1;
}

int get_right_child_index(heap* _heap, int idx) {
    return (((idx * 2) + 2) < _heap->size) ? (idx * 2) + 2 : -1;
}

void extend_heap(heap* _heap) {
    int* new_arr = (int*)calloc(_heap->max_size*2, sizeof(int));
    memcpy(new_arr, _heap->arr, _heap->max_size * sizeof(int));
    free(_heap->arr);
    _heap->arr = new_arr;
}

int heapify_up(heap* _heap) {

    int current_idx = _heap->size - 1;
    int parent_idx = get_parent_index(_heap->size - 1);
    int temp = 0;

    while ((_heap->type == max && _heap->arr[current_idx] > _heap->arr[parent_idx]) || (_heap->type == min && _heap->arr[current_idx] < _heap->arr[parent_idx])) {

        temp = _heap->arr[current_idx];
        _heap->arr[current_idx] = _heap->arr[parent_idx];
        _heap->arr[parent_idx] = temp;

        current_idx = parent_idx;
        parent_idx = get_parent_index(current_idx);
    }

    return current_idx;
}

void heapify_down(heap* heap, int current_idx) {
    int temp = 0;
    int left_child_idx = 0;
    int right_child_idx = 0;

    left_child_idx = get_left_child_index(heap, current_idx);
    right_child_idx = get_right_child_index(heap, current_idx);

    while ((left_child_idx != -1 && compare(heap->type, heap->arr[left_child_idx], heap->arr[current_idx])) || (right_child_idx != -1 && compare(heap->type, heap->arr[right_child_idx], heap->arr[current_idx]))) {

        if ((right_child_idx != -1 && compare(heap->type, heap->arr[right_child_idx], heap->arr[left_child_idx]))) {
            temp = heap->arr[current_idx];
            heap->arr[current_idx] = heap->arr[right_child_idx];
            heap->arr[right_child_idx] = temp;
            current_idx = right_child_idx;
        }
        else {
            temp = heap->arr[current_idx];
            heap->arr[current_idx] = heap->arr[left_child_idx];
            heap->arr[left_child_idx] = temp;
            current_idx = left_child_idx;
        }

        right_child_idx = get_right_child_index(heap, current_idx);
        left_child_idx = get_left_child_index(heap, current_idx);
    }
}

void push(heap* _heap, int val) {

    if (_heap->size == _heap->max_size) {
        extend_heap(_heap);
    }

    _heap->arr[_heap->size] = val;
    _heap->size++;

    int current_idx = heapify_up(_heap);

    heapify_down(_heap, current_idx);

}

int pop(heap* _heap) {

    int result = _heap->arr[0];

    _heap->size--;
    _heap->arr[0] = _heap->arr[_heap->size];

    heapify_down(_heap, 0);

    return result;
}

int get_top(heap* _heap) {
    return _heap->arr[0];
}
