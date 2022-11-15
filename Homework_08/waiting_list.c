/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 8: Waiting List
* File: waiting_list.c
* File type: Homework
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "waiting_list.h"

struct WaitingList *new_empty_waiting_list() {
    struct WaitingList *ptr = calloc(1, sizeof(struct WaitingList));
    if (ptr == NULL) {
        return 0;
    }
    return ptr;
}

struct Student *create_student() {
    struct Student *ptr = calloc(100, sizeof(struct Student));
    if (ptr == NULL) {
        return 0;
    }
    return ptr;
}

struct Node *create_node() {
    struct Node *ptr = calloc(100, sizeof(struct Node));
    if (ptr == NULL) {
        return 0;
    }
    return ptr;
}

void add_student(struct WaitingList *list, char name[50], int matr_nr, int semester) {
    struct Node *nod = create_node();
    struct Student *stu = create_student();
    nod->s = stu;

    for (int i = 0; i < 50; i++) {
        stu->name[i] = name[i];
    }
    stu->matr_nr = matr_nr;
    stu->semester = semester;

    if (list->tail == NULL) {
        list->head = nod;
    } else {
        list->tail->next = nod;
    }

    nod->previous = list->tail;
    list->tail = nod;
}

struct Student *pop_student(struct WaitingList *list) {

    if (list->head == NULL) {
        return NULL;
    }

    struct Student *ptr = list->head->s;

    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        struct Node *new_head = list->head->next;
        free(list->head);
        list->head = new_head;
    }

    return ptr;
}

int get_list_length(struct WaitingList *list) {
    int num = 0;

    if (list->head == NULL) {
        return num;
    }

    num++;
    struct Node *ptr = list->head->next;

    while (ptr != NULL) {
        num++;
        ptr = ptr->next;
    }

    return num;
}

int is_waiting(struct WaitingList *list, int matr_nr) {

    int num = 0;
    struct Node *node = list->head;

    if (node == NULL) {
        return num;
    }

    while (num != 1) {
        if (node->s->matr_nr == matr_nr) {
            num++;
        } else if (node->next == NULL) {
            break;
        } else {
            node = node->next;
        }
    }

    return num;
}

void add_vip(struct WaitingList *list, char name[50], int matr_nr, int semester) {
    struct Node *vip_n = create_node();
    struct Student *vip_s = create_student();
    vip_n->s = vip_s;

    for (int i = 0; i < 50; i++) {
        vip_s->name[i] = name[i];
    }
    vip_s->matr_nr = matr_nr;
    vip_s->semester = semester;

    if (list->head == NULL) {
        list->tail = vip_n;
    } else {
        list->head->previous = vip_n;
    }

    vip_n->next = list->head;
    list->head = vip_n;
}

void clear_list(struct WaitingList *list) {

    struct Node *n = list->head;
    struct Node *old_n = NULL;

    if (n == NULL) {

    } else {
        while (n->next != NULL) {
            old_n = n;
            n = n->next;
            free(old_n->s);
            free(old_n);
        }

        free(n->s);
        free(n);
    }

    list->head = NULL;
    list->tail = NULL;
}