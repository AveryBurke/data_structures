#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *a, int low, int high){

    if (high <= low){ return; }

    merge_sort(a, low, (high + low)/2);
    merge_sort(a, ((high + low)/2) + 1, high);

    int mid = (high + low) / 2;
    int idx1 = low;
    int idx2 = mid + 1;
    int i = 0;
    int *place_holder = malloc((high - low + 1) * sizeof(int));
    while (idx1 <= mid && idx2 <= high){
        if (a[idx1] < a[idx2]){
            place_holder[i] = a[idx1];
            idx1++;
        } else {
            place_holder[i] = a[idx2];
            idx2++;
        }
        i++;
    }

    while (idx1 <= mid){
        place_holder[i] = a[idx1];
        i++;
        idx1++;
    }

    while (idx2 <= high){
        place_holder[i] = a[idx2];
        i++;
        idx2++;
    }
    for (size_t i = 0; i < high - low + 1; i++)
    {
        a[i + low] = place_holder[i];
    }
    free(place_holder);
}

void merge_sort_wrapper(int *a, size_t length){
    merge_sort(a, 0, length - 1);
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 4, 3, 2};
    merge_sort_wrapper(a, 4);
    printf("[ ");
    for (size_t i = 0; i < 4; i++)
    {
        printf("%d, ", a[i]);
    }
    printf(" ]\n");
    
    return 0;
}
