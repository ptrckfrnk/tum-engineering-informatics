/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 7: Towers of Hanoi
* File: hanoi.c
* File type: Template File
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hanoi.h"

//IMPORTANT
//For this HW, you are allowed to code outside of the marked spots. You may
//define own functions, but of course you are still not allowed to include
//any additional libraries. But there actually is no need to define own functions,
//the recursive solution for move() only contains 4 additional lines of code.


/**
* allocate_trace
*
* This function calculates how many steps will be neccessary, allocates enough
* memory to store those steps, initializes this memory to 0, and returns a
* pointer to the allocated memory.
*
* MEMORY : <important notes >
*
* @param disks is the number of disks
*
* @return is a pointer to the newly allocated and initialized char array
*
*/
char *allocate_trace(int disks){
    char *ptr = 0;
    //YOUR CODE STARTS HERE

    ptr = calloc(pow(2, disks+1), sizeof(*ptr));

    //YOUR CODE ENDS HERE
    if(ptr == 0){
        printf("No memory available!\n");
    }
    return ptr;
}

/**
* write
*
* This function can be used to store a move into the trace array. Through the
* use of a static local variable as index, we always write at the current position
* in the array.
*
* MEMORY : <important notes >
*
* @param array is a pointer to the array
* @param source is the source stack of disks
* @param target is the target stack
*
* @return is only used for correction, treat this function as if it was a void function
*
*/
int* write(char *array, char source, char target){
    static int index = 0;
    array[index++] = source;
    array[index++] = target;
    return &index; //needed for correction, ignore this line
}


/**
* move
*
* This function is called once by the main, and automatically performs the
* entire process from moving the stack of disks from source to target. As it
* is recursive, it calls itself multiple times and consists of a base case,
* and a recursive case.
*
* MEMORY : <important notes >
*
* @param disks the number of disks
* @param source is the source stack of disks
* @param target is the target stack
* @param helper is the auxiliary stack
* @param trace is the array where we write our steps in
*
*
*/
//IF YOU WANT TO, YOU CAN CHANGE THIS FUNCTION'S STRUCTURE, BUT IT IS EASIER IF YOU DON'T
void move(int disks, char source, char target, char helper, char *trace){
    if(disks == 1){
        //YOUR CODE STARTS HERE

        write(trace, source, target);

        //YOUR CODE ENDS HERE
    }
    else{
        //YOUR CODE STARTS HERE

        move(disks-1, source, helper, target, trace);
        move(1, source, target, helper, trace);
        move(disks-1, helper, target, source, trace);

        //YOUR CODE ENDS HERE
    }
}
