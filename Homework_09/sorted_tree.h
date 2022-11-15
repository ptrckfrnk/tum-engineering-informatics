/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 9: Sorted Tree
* File: sorted_tree.h
* File type: Template File
*****************************************************************/

#ifndef SORTED_TREE_H
#define SORTED_TREE_H



struct TreeNode{
    int value;
    struct TreeNode* left_child;
    struct TreeNode* right_child;
};

void print_inorder(struct TreeNode *n);
int insert_value(int value, struct TreeNode *n);


#endif //SORTED_TREE_H
