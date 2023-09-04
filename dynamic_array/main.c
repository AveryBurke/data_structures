#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array.h"

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
