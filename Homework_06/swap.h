/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 6: Swapping with Pointers
* File: swap.h
* File type: Template file
*****************************************************************/

//DO NOT CHANGE ANYTHING IN THIS FILE
#ifndef SWAP_H
#define SWAP_H

struct rectangle{
    char color[10];
    int length;
    int width;
};

void swap_ints(int *a, int *b);
void swap_rectangle(struct rectangle *r1, struct rectangle *r2);
void print_rectangle(struct rectangle *r);
void initialize_rectangle(struct rectangle *r, char color[20], int length, int width);

#endif //SWAP_H
