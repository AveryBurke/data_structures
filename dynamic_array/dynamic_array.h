#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct vector
{
    int length;
    int capacitiy;
    int *array;
} vector;

void init_array(int capacity, vector *v);
void resize_array(int size, vector *v);
int  append(int item, vector *v);

#endif // DYNAMIC_ARRAY_H
