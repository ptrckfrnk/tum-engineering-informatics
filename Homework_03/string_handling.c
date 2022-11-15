/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 3: String Handling
* File: string_handling.c
* File type: Template file
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**
* to_lower
*
* This function converts all higher case to lower case letters
*
* MEMORY : <important notes >
*
* @param array is the string to convert (NULL-terminated)
*
*/
void to_lower(char array[]){
    ////YOUR CODE STARTS HERE

    int i = 0;

    while (array[i] != 0) {
        if (array[i] >= 65 && array[i] <= 90) {
            array[i] += 32;
        }
        i++;
    }

    ////END OF YOUR CODE
}


/**
* detect
*
* This function tests array for appearances of code
*
* MEMORY : <important notes >
*
* @param array is the string in which we will search
* @param code is what we are looking for in array
*
* @return 1 if code appears in array, 0 otherwise
*/
int detect(char array[], char code[]){
    ////YOUR CODE STARTS HERE

    int i = 0;
    int j = 0;
    int det = 0;

    while (array[i] != 0) {
        if (array[i] == code[j]) {
            while (code[j] != 0) {
                if (array[i] != code[j]) {
                    det = 0;
                    j = 0;
                    break;
                } else {
                    det = 1;
                }
                i++;
                j++;
            }
        }
        i++;
    }

    return det;

    ////END OF YOUR CODE
}


/**
* clean
*
* This function cleans arrays from appearances of spam chars
*
* MEMORY : <important notes >
*
* @param array is the string to clean (NULL-terminated)
* @param spam is the character we want to erase out of array
*
*/
void clean(char array[], char spam){
    ////YOUR CODE STARTS HERE

    int i = 0;
    int j = 0;

    while (array[i] != 0) {
        while (array[i] == spam) {
            j = i;
            while (array[j] != 0) {
                array[j] = array[j+1];
                j++;
            }
            j = 0;
        }
        i++;
    }

    ////END OF YOUR CODE
}