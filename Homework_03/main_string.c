
/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 3: String Handling
* File: main_string.c
* File type: Testing file for students
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "string_handling.c"

//removes the Enter from the string, necessary to process the strings with your functions
void remove_enter(char array[]){
    int i = 0;
    while(array[i] != 0){
        if(array[i] == 10){
            array[i] = 0;
            break;
        }
        i++;
    }
}

int main(){
    printf("Which function do you want to test?\nto_lower (t), detect (d), clean (c): ");
    char buffer[100]={0};
    char buffer2[100]={0};
    fgets(buffer,99,stdin);
    switch(buffer[0]){
        case 'd':
            printf("Specify input 'array': ");
            fgets(buffer,99,stdin);
            remove_enter(buffer);
            printf("Specify input 'code': ");
            fgets(buffer2,99,stdin);
            remove_enter(buffer2);
            printf("Returned value of your function: %d",detect(buffer,buffer2));
            break;
        case 't':
            printf("Specify input 'array': ");
            fgets(buffer,99,stdin);
            remove_enter(buffer);
            to_lower(buffer);
            printf("'array' after run of your function: %s",buffer);
            break;
        case 'c':
            printf("Specify input 'array': ");
            fgets(buffer,99,stdin);
            remove_enter(buffer);
            printf("Specify input 'spam': ");
            fgets(buffer2,99,stdin);
            remove_enter(buffer2);
            clean(buffer,buffer2[0]);
            printf("'array' after run of your function: %s",buffer);
            break;
        default:
            printf("Invalid input!");
            break;
    }

}