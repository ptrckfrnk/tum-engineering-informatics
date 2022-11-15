/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 10: Counting Sort
* File: counting_sort.c
* File type: Template File
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

void counting_sort(int *array, int length){
    //YOUR CODE STARTS HERE
    if (array == NULL) {
        return;
    }

    int min = 0;
    int max = 0;

    for (int i = 0; i < length; i++) {
        int val = *(array+i);

        if (val < min) {
            min = val;
        }

        if (val > max) {
            max = val;
        }
    }

    int *histo = calloc(max-min+1, sizeof(int));

    for (int i = 0; i < length; i++) {
        int val = *(array+i);
        *(histo+(val-min)) = *(histo+(val-min)) + 1;
    }

    int index = 0;

    for (int i = 0; i < max-min+1; i++) {
         int num = i + min;
         int count = *(histo+i);

         while (count != 0) {
             *(array+index) = num;
             index++;
             count--;
         }
    }
    //YOUR CODE ENDS HERE
}