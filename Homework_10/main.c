#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

int main(){

    int length = 1;

    int test[11] = {4};
    printf("Testing your function with the following array: {");
    for(int i = 0; i<length-1; i++){
        printf("%d, ", test[i]);
    }
    printf("%d}\n", test[length-1]);
    printf("Calling your function...\n");
    counting_sort(test, length);
    printf("Printing the results: {");
    for(int i = 0; i<length-1; i++){
        printf("%d, ", test[i]);
    }
    printf("%d}\n", test[length-1]);
}
