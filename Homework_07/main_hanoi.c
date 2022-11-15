/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 7: Towers of Hanoi
* File: main_hanoi.c
* File type: Testing for students
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"


//With this main function, you can test your results. Understanding this main may help you coding.
int main(){

    //Getting user input for the number of disks for the game
    printf("Number of disks: ");
    char buffer[10] = {0};
    fgets(buffer, 10, stdin);
    int disks = atoi(buffer); //assuming valid input

    //Testing if allocation function works and initializes enough memory to 0
    printf("Testing allocate_trace...\n");
    char *ptr = allocate_trace(3); //Test allocation to check memory size
    for(int i = 0; i<16; i++){
        if(ptr[i]!=0){
            printf("Failed allocation test:\n You either allocated to few memory, or you forgot to initialize to 0!");
            printf("Remember to allocate exactly as much space as specified in the sheet.\n\n");
            break;
        }
    }
    free(ptr);

    //Starting the game
    printf("Calculating trace array...\n");
    //Allocate enough memory to trace the steps
    char *array = allocate_trace(disks);

    //Calling the move-function to start recursive process
    move(disks, 'A', 'C', 'B', array);

    //print the chars in the trace array according to the convention from the HW-sheet
    printf("Calculated trace of your program:\n");
    int i = 0;
    while(array[i]!=0){ //Iterating to the end of the array, as it is always NULL-terminated
        printf("%c -> ", array[i++]); //Source
        printf("%c ", array[i++]); //Destination
        printf("(Move No. %d)\n", i/2); //Number of move
    }

    //Free the allocated memory as it isn't used any more
    free(array);


    printf("\nPlease check by yourself whether these steps yield the shortest possible solution.");
}
