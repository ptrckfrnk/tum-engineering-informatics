/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 8: Waiting List
* File: main_list.c
* File type: Testing
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "waiting_list.h"


struct WaitingList *test_create_list(){
    struct WaitingList *list = new_empty_waiting_list();
    if(list->head != NULL || list ->tail != NULL){
        printf("At least one member of the new list is not correctly initialized!\n");
        printf("0 cases passed\n");
        exit(0);
    }
    return list;
}

int check_output(struct Student *s, char *name, int matr_nr, int semester){
    int correct = 1;
    for(int i = 0; i<50; i++){
        if(s->name[i] == 0 && name[i]==0){
            break;
        }
        else if(s->name[i] != name[i]){
            printf("\t\tError: Expected name %s, but got %s\n", name, s->name);
            correct = 0;
            break;
        }
    }

    if(s->matr_nr != matr_nr){
        printf("\t\tError: Expected matr_nr does not match return value!\n");
        correct = 0;
    }
    if(s->semester != semester){
        printf("\t\tError: Expected semester does not match return value!\n");
        correct = 0;
    }
    if(correct == 0){
        printf("\n");
    }
    return correct;
}

void test_concatenation(struct WaitingList *list, int *passed){
    char names[6][50] = {{"Dominik"}, {"Katharina"}, {"Melvin"}, {"Martin"}, {"Fynn"}, {"Aliya"}};
    int matr_nrs[6] = {1234, 5678, 9012, 3456, 7890, 9876};
    int semesters[6] = {1, 3, 7, 7, 5, 5};
    printf("\tPopping, checking output...\n");
    struct Student *s = pop_student(list);
    if(s != NULL){
        printf("\t\tError: Expected NULL-Pointer as list should be empty, did not get NULL-Pointer.\n");
    }
    else{(*passed)++;}
    printf("\tAdding student to list...\n");
    add_student(list, names[0], matr_nrs[0], semesters[0]);
    printf("\tPopping, checking output...\n");
    *passed += check_output(pop_student(list), names[0], matr_nrs[0], semesters[0]);
    printf("\tPopping, checking output...\n");
    s = pop_student(list);
    if(s != NULL){
        printf("\t\tError: Expected NULL-Pointer as list should be empty, did not get NULL-Pointer.\n");
    }
    else{(*passed)++;}
    printf("\tAdding student to list...\n");
    add_student(list, names[1], matr_nrs[1], semesters[1]);
    printf("\tAdding student to list...\n");
    add_student(list, names[2], matr_nrs[2], semesters[2]);
    printf("\tPopping, checking output...\n");
    *passed += check_output(pop_student(list), names[1], matr_nrs[1], semesters[1]);
    printf("\tAdding student to list...\n");
    add_student(list, names[3], matr_nrs[3], semesters[3]);
    printf("\tAdding student to list...\n");
    add_student(list, names[4], matr_nrs[4], semesters[4]);
    printf("\tPopping, checking output...\n");
    *passed += check_output(pop_student(list), names[2], matr_nrs[2], semesters[2]);
    printf("\tPopping, checking output...\n");
    *passed += check_output(pop_student(list), names[3], matr_nrs[3], semesters[3]);
    printf("\tAdding student to list...\n");
    add_student(list, names[5], matr_nrs[5], semesters[5]);
    printf("\tPopping, checking output...\n");
    *passed += check_output(pop_student(list), names[4], matr_nrs[4], semesters[4]);
    printf("\tPopping, checking output...\n");
    *passed += check_output(pop_student(list), names[5], matr_nrs[5], semesters[5]);
    printf("\tPopping, checking output...\n");
    s = pop_student(list);
    if(s != NULL){
        printf("\t\tError: Expected NULL-Pointer as list should be empty, did not get NULL-Pointer.\n");
    }
    else{(*passed)++;}
}

void test_others(struct WaitingList *list, int *passed){
    char names[6][50] = {{"Sybille"}, {"Manuel"}, {"Moritz"}, {"Stephanie"}, {"Anja"}, {"Markus"}};
    int matr_nrs[6] = {1123, 4567, 8901, 2345, 6789, 9987};
    int semesters[6] = {1, 3, 7, 5, 5, 1};
    printf("\tAdding normal student to list...\n");
    add_student(list, names[0], matr_nrs[0], semesters[0]);
    printf("\tAdding vip-student to list...\n");
    add_vip(list, names[1], matr_nrs[1], semesters[1]);
    printf("\tAdding normal student to list...\n");
    add_student(list, names[2], matr_nrs[2], semesters[2]);

    printf("\tPopping, checking output (2 cases)...\n");
    *passed += (check_output(pop_student(list), names[1], matr_nrs[1], semesters[1]) * 2);

    printf("\tAdding vip-student to list...\n");
    add_vip(list, names[3], matr_nrs[3], semesters[3]);

    printf("\tAdding normal student to list...\n");
    add_student(list, names[4], matr_nrs[4], semesters[4]);

    printf("\tCalling get_list_length()...\n");
    int l = get_list_length(list);
    if(l != 4){
        printf("\t\tError: Expected length %d, but got %d.\n", 4, l);
    }
    else{
        (*passed)++;
    }

    printf("\tCalling is_waiting() (2 cases)...\n");
    if(is_waiting(list, matr_nrs[4]) == 0){
        printf("\t\tError: matr_nr was not found, but should be there.\n");
    }
    else{
        (*passed)+=2;
    }

    printf("\tCalling is_waiting()...\n");
    if(is_waiting(list, matr_nrs[5]) == 1){
        printf("\t\tError: matr_nr was found, but should not be there.\n");
    }
    else{
        (*passed)++;
    }

    printf("\tPopping, checking output (2 cases)...\n");
    *passed += (check_output(pop_student(list), names[3], matr_nrs[3], semesters[3]) * 2);

    printf("\tCalling clear_list()...\n");
    clear_list(list);
    if(list->head != NULL || list->tail != NULL){
        printf("\t\tError: List head or tail are not NULL after call of clear_list (2 cases).\n");
    }
    else{
        (*passed)+=3;
    }

    printf("\tCalling get_list_length() (2 cases)...\n");
    l = get_list_length(list);
    if(l != 0){
        printf("\t\tError: Expected length %d, but got %d.\n", 0, l);
    }
    else{
        (*passed)+=2;
    }

    printf("\tCalling is_waiting()...\n");
    if(is_waiting(list, matr_nrs[4]) == 1){
        printf("\t\tError: matr_nr was found, but should not be there.\n");
    }
    else{
        (*passed)++;
    }

    printf("\tAdding vip-student to list...\n");
    add_vip(list, names[5], matr_nrs[5], semesters[5]);

    printf("\tCalling get_list_length()...\n");
    l = get_list_length(list);
    if(l != 1){
        printf("\t\tError: Expected length %d, but got %d.\n", 1, l);
    }
    else{
        (*passed)++;
    }

    printf("\tCalling is_waiting()...\n");
    if(is_waiting(list, matr_nrs[5]) == 0){
        printf("\t\tError: matr_nr was not found, but should be there.\n");
    }

    else{
        (*passed)++;
    }
    printf("\tPopping, checking output (2 cases)...\n");
    *passed += (check_output(pop_student(list), names[5], matr_nrs[5], semesters[5]) * 2);
}


int main(){

    printf("Testing new_empty_waiting_list (3 cases)...\n");
    struct WaitingList *list = test_create_list();
    int passed = 3;
    printf("\nTesting add_student and pop_student (9 cases)...\n");
    test_concatenation(list, &passed);
    free(list);
    list = test_create_list();
    printf("\nTesting add_vip (6 cases), get_list_length (4 cases), is_waiting (5 cases) and clear_list (3 cases)...\n");
    test_others(list, &passed);
    printf("\nPassed %d/30 cases", passed);
}
