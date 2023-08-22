#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array.h"

/* TO DO: Add pop */

void init_array(int capacity, vector *v){
    /* capacity can't be zero */
    v->capacitiy = capacity > 0 ? capacity : 1;
    v->capacitiy = capacity;
    v->length = 0;
    v->array = calloc(capacity, sizeof (int));
    return;
}

void resize_array(int size, vector *v){
    int *new_array = calloc(size, sizeof (int));
    for (int i = 0; i < v->length; ++i){
        new_array[i] = v->array[i];
    }
    free(v->array);
    v->capacitiy = size;
    v->array = new_array;
    return;
}

/* adds an item to the end of the vectore and returns the new length */
int append(int item, vector *v){
    if(v->length == v->capacitiy){
        resize_array(v->capacitiy * 2, v);
    }
    v->array[v->length] = item;
    ++v->length;
    return v->length;
}

