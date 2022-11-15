/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 9: Sorted Tree
* File: sorted_tree.c
* File type: Template File
*****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "sorted_tree.h"


int insert_value(int value, struct TreeNode *n){
    //YOUR CODE STARTS HERE

    if (value == n->value) {
        return 1;
    } else if (value < n->value) {
        if (n->left_child == NULL) {
            struct TreeNode *ptr = calloc(1, sizeof(struct TreeNode));
            ptr->value = value;
            n->left_child = ptr;
            return 0;
        } else {
            insert_value(value, n->left_child);
        }
    } else {
        if (n->right_child == NULL) {
            struct TreeNode *ptr = calloc(1, sizeof(struct TreeNode));
            ptr->value = value;
            n->right_child = ptr;
            return 0;
        } else {
            insert_value(value, n->right_child);
        }
    }

    return 0;
    //YOUR CODE ENDS HERE
}

void print_inorder(struct TreeNode *n){
    if(n == NULL){
        return;
    }
    else{
        print_inorder(n->left_child);
        printf("%d ", n->value);
        print_inorder(n->right_child);
    }
}