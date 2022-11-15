/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 8: Waiting List
* File: waiting_list.h
* File type: Template File
*****************************************************************/

#ifndef HOMEWORK_8_WAITING_LIST_H
#define HOMEWORK_8_WAITING_LIST_H

struct Student{
    char name[50];
    int matr_nr;
    int semester;
};

struct Node{
    struct Student *s;
    struct Node *next;
    struct Node *previous;
};

struct WaitingList{
    struct Node *head;
    struct Node *tail;
};

//function declarations
struct WaitingList *new_empty_waiting_list();
void add_student(struct WaitingList *list, char name[50], int matr_nr, int semester);
struct Student *pop_student(struct WaitingList *list);
int get_list_length(struct WaitingList *list);
int is_waiting(struct WaitingList *list, int matr_nr);
void add_vip(struct WaitingList *list, char name[50], int matr_nr, int semester);
void clear_list(struct WaitingList *list);


#endif //HOMEWORK_8_WAITING_LIST_H
