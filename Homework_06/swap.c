/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 6: Swapping with Pointers
* File: swap.c
* File type: Template file
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "swap.h"


/**
* swap_ints
*
* This function swaps the values of two ints that it recieves by reference
*
* MEMORY : <important notes >
*
* @param a is the pointer to the first int to be swapped
* @param b is the pointer to the second int to be swapped
*
*/
void swap_ints(int *a, int *b){
    //YOUR CODE STARTS HERE

    int x = *a;
    *a = *b;
    *b = x;

    //YOUR CODE ENDS HERE
}



/**
* initialize_rectangle
*
* This function initializes a struct rectangle with given values for the variables
*
* MEMORY : <important notes >
*
* @param r is the pointer to the newly created rectangle to be initialized with the following values
* @param color is a char array containing the color of the rectangle
* @param length is the length of the rectangle
* @param width is the width of the rectangle
*
*/
void initialize_rectangle(struct rectangle *r, char color[20], int length, int width){
    //YOUR CODE STARTS HERE

    (*r).length = length;
    (*r).width = width;

    for (int i = 0; i < 10; i++) {
        (*r).color[i] = color[i];
    }

    //YOUR CODE ENDS HERE
}




/**
* print_rectangle
*
* This function prints the stats of the given rectangle. ONLY USE THIS FUNCTION TO TEST YOUR FUNCTIONS DURING
* DEVELOPEMENT! DON'T CALL THIS FUNCTION IN THE FINAL VERSION OF YOUR FILE!
*
* MEMORY : <important notes >
*
* @param r is the pointer to the rectangle to be printed
*
*/
void print_rectangle(struct rectangle *r){
    printf("Stats of rectangle:\n");
    printf("Color: %s\n", r->color);
    printf("Length: %d\n", r->length);
    printf("Width: %d\n", r->width);
}


/**
* swap_rectangle
*
* This function swaps the values of two struct rectangles that it recieves by reference
*
* MEMORY : <important notes >
*
* @param r1 is the pointer to the first rectangle to be swapped
* @param r2 is the pointer to the second rectangle to be swapped
*
*/
void swap_rectangle(struct rectangle *r1, struct rectangle *r2){
    //YOUR CODE STARTS HERE

    struct rectangle x;
    x.length = r1->length;
    x.width = r1->width;
    for (int i = 0; i < 10; i++) {
        x.color[i] = r1->color[i];
    }

    r1->length = r2->length;
    r1->width = r2->width;
    for (int i = 0; i < 10; i++) {
        r1->color[i] = r2->color[i];
    }

    r2->length = x.length;
    r2->width = x.width;
    for (int i = 0; i < 10; i++) {
        r2->color[i] = x.color[i];
    }

    //YOUR CODE ENDS HERE
}



