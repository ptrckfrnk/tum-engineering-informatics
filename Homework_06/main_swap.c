/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 6: Swapping with Pointers
* File: main_swap.c
* File type: Testing for students
*****************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "swap.h"
int passed = 0;
int failed = 0;

void test_swap_ints(int *int_val, int *control_int_val){
    printf("Testing swap_ints...\n");
    for(int i = 0; i<2; i++){
        swap_ints(int_val+i, int_val+3-i);
    }
    for(int i = 0; i<4; i++){
        if(int_val[i] != control_int_val[3-i]){
            printf("Failed test case 1.%d:\n", i+1);
            printf("Error at swapping: Your int is %d, whereas correct would be %d.\n\n",int_val[i], control_int_val[3-i]);
            failed++;
        }
        else{
            passed++;
        }
    }
}

void test_initialize_rectangle(struct rectangle *rec, struct rectangle *control_rec){
    printf("Testing initialize_rectangle...\n");
    initialize_rectangle(rec, "Green", 1, 2);
    initialize_rectangle(rec+1, "Red", 3, 4);

    for(int i=0; i<2; i++){
        //Compare color
        for(int j = 0; j<10; j++){
            if(rec[i].color[j] != control_rec[i].color[j]){
                printf("Failed test case 2.%d.1:\n", i+1);
                printf("You initialized color to \"%s\", whereas function argument was \"%s\".\n\n",rec[i].color, control_rec[i].color);
                failed++;
                break;
            }
            else if(rec[i].color[j] == 0){
                passed++;
                break;
            }
        }

        //Compare length
        if(rec[i].length != control_rec[i].length){
            printf("Failed test case 2.%d.2:\n", i+1);
            printf("You initialized length to %d, whereas function argument was %d.\n\n",rec[i].length, control_rec[i].length);
            failed++;
        }
        else{
            passed++;
        }

        //Compare width
        if(rec[i].width != control_rec[i].width){
            printf("Failed test case 2.%d.3:\n", i+1);
            printf("You initialized width to %d, whereas function argument was %d.\n\n",rec[i].width, control_rec[i].width);
            failed++;
        }
        else{
            passed++;
        }
    }
}

void test_swap_rectangle(struct rectangle *rec, struct rectangle *control_rec){
    printf("Testing swap_rectangle...\n");
    swap_rectangle(rec, rec+1);
    for(int i = 0; i<2; i++){
        //Compare color
        for(int j = 0; j<10; j++){
            if(rec[i].color[j] != control_rec[1-i].color[j]){
                printf("Failed test case 3.%d.1:\n", i+1);
                printf("Error at swapping: Your color is \"%s\", whereas correct would be \"%s\".\n\n",rec[i].color, control_rec[1-i].color);
                failed++;
                break;
            }
            else if(rec[i].color[j] == 0){
                passed++;
                break;
            }
        }

        //Compare length
        if(rec[i].length != control_rec[1-i].length){
            printf("Failed test case 3.%d.2:\n", i+1);
            printf("Error at swapping: Your length is %d, whereas correct would be %d.\n\n",rec[i].length, control_rec[1-i].length);
            failed++;
        }
        else{
            passed++;
        }

        //Compare width
        if(rec[i].width != control_rec[1-i].width){
            printf("Failed test case 3.%d.3:\n", i+1);
            printf("Error at swapping: Your width is %d, whereas correct would be %d.\n\n",rec[i].width, control_rec[1-i].width);
            failed++;
        }
        else{
            passed++;
        }

    }
}

int main(){

    int int_val[4] = {1, 2, 3, 4};
    int control_int_val[4] = {1, 2, 3, 4};

    struct rectangle rec[2];
    struct rectangle control_rec[2] = {{"Green", 1, 2}, {"Red", 3, 4}};


    test_swap_ints(int_val, control_int_val);
    test_initialize_rectangle(rec, control_rec);
    test_swap_rectangle(rec, control_rec);

    printf("\n\nTOTAL SCORE: %d / % d\n",passed, passed+failed);
    printf("Please note that these testcases are only for your orientation and do not represent the testcases we will use to correct your homework.");

}

