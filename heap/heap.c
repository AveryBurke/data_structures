#include <stdio.h>
#include <stdlib.h>

enum {max, min};

typedef struct max_heap{

    int size;
    int max_size;
    int* arr;

    int type;

}max_heap;

void init_heap(max_heap* heap, int _max_size, int _type) {
    heap->size = 0;
    heap->max_size = _max_size;
    heap->arr = (int*)calloc(_max_size, sizeof(int));
    heap->type = _type;
}

void destory_heap(max_heap* heap) {
    free(heap->arr);
}

int get_parent_index(int idx) {
    return (idx - 1) / 2;
}

int get_left_child_index(max_heap* heap, int idx) {
    return (((idx * 2) + 1) < heap->size) ? (idx*2) + 1 : -1;
}

int get_right_child_index(max_heap* heap, int idx) {
    return (((idx * 2) + 2) < heap->size) ? (idx * 2) + 2 : -1;
}

int heapify_up(max_heap* heap) {

    int current_idx = heap->size - 1;
    int parent_idx = get_parent_index(heap->size - 1);
    int temp = 0;

    while ((heap->type == max && heap->arr[current_idx] > heap->arr[parent_idx]) || (heap->type == min && heap->arr[current_idx] < heap->arr[parent_idx])) {

        temp = heap->arr[current_idx];
        heap->arr[current_idx] = heap->arr[parent_idx];
        heap->arr[parent_idx] = temp;

        current_idx = parent_idx;
        parent_idx = get_parent_index(current_idx);
    }

    return current_idx;
}

int compare(int type, int val_1, int val_2) {

    if (type == max) {
        return (val_1 > val_2) ? 1 : 0;
    }

    return (val_1 < val_2) ? 1 : 0;
}

void heapify_down(max_heap* heap, int current_idx) {
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
        else  {
            temp = heap->arr[current_idx];
            heap->arr[current_idx] = heap->arr[left_child_idx];
            heap->arr[left_child_idx] = temp;
            current_idx = left_child_idx;
        }

        right_child_idx = get_right_child_index(heap, current_idx);
        left_child_idx = get_left_child_index(heap, current_idx);
    }
}

void push(max_heap* heap, int val) {

    if (heap->size == heap->max_size) {
        return;
    }

    heap->arr[heap->size] = val;

    heap->size++;
    int current_idx = heapify_up(heap);

    heapify_down(heap, current_idx);

}

int pop(max_heap* heap) {

    int result = heap->arr[0];

    heap->size--;
    heap->arr[0] = heap->arr[heap->size];

    heapify_down(heap, 0);

    return result;
}

int get_top(max_heap* heap) {
    return heap->arr[0];
}
//
// Created by Conrad on 2023-09-04.
//
