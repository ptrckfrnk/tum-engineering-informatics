/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 10: Counting Sort
* File: main_sort.c
* File type: Testing for students
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

int main(){
    int test[11] = {3, 7, -2, -7, 4, 3, 0, 4, 1, 2};
    printf("Testing your function with the following array: {");
    for(int i = 0; i<9; i++){
        printf("%d, ", test[i]);
    }
    printf("%d}\n", test[9]);
    printf("Calling your function...\n");
    counting_sort(test, 10);
    printf("Printing the results: {");
    for(int i = 0; i<9; i++){
        printf("%d, ", test[i]);
    }
    printf("%d}\n", test[9]);
    printf("Please check by yourself if these values are correct. Testing correct memory handling...\n");
    if(test[10] != 0){
        printf("ERROR! You wrote on index 10 of test array, even though the length provided to your function was 10. Your function writes on invaild memory!");
    }
    else{
        printf("Memory handling correct.\n");
    }
}