#include <stdlib.h>
#include <stdio.h>


/* TO DO: Add pop */

typedef struct vector
{
    int length;
    int capacitiy;
    int *array;
} vector;

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

int main(int argc, char const *argv[])
{
    vector v;
    init_array(8, &v);
    printf("capacity: %d\n", v.capacitiy);
    printf("length: %d\n", v.length);
    for (int i = 0; i < 100; ++i){
        append(i, &v);
    }
    for (int i = 0; i < v.length; ++i){
        printf("%d ", v.array[i]);
    }
    printf("\nthe capacity is now %d", v.capacitiy);
    return 0;
}
