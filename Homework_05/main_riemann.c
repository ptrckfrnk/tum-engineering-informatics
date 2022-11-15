
/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 4: Numerical Integration
* File: main_riemann_correction.c
* File type: Testing for students
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funct_lib.h"
#include "riemann.h"

int passed = 0;
int failed = 0;
double h = 0.01;
double tolerance = 0.01;

void test_integrate_midpoint(){
    printf("Testing integrate_midpoint...\n");
    double input[5][3] = {{0.0,1.0,h},{-1.0,0.0,h},{0.0,3.0,h},{-3.0,-0.5,h}, {0.0,10.0,h}};
    double solution[5] = {0.250000, -0.250000, 20.250000, -20.234375, 2500.000000};
    for(int i = 0; i<5; i++){
        double error = fabs(integrate_midpoint(funct_x3,input[i][0], input[i][1], input[i][2])-solution[i]);
        if(error <= tolerance){
            passed++;
        }
        else{
            failed++;
            printf("Failed case 1.%d: Input: (funct_x3, %f, %f, %f)\n",i+1,input[i][0], input[i][1], input[i][2]);
            printf("Error is %f, tolerance is %f\n\n",error, tolerance);
        }
    }
}

void test_integrate_left(){
    printf("Testing integrate_left...\n");
    double input[5][3] = {{0.0,1.0,h},{-1.0,0.0,h},{0.0,3.0,h},{-3.0,-0.5,h}, {0.0,10.0,h}};
    double solution[5] = {0.746824, 0.746824, 0.886208, 0.424926, 0.886227};
    for(int i = 0; i<5; i++){
        //printf("%f, ",integrate_left(funct_gauss,input[i][0], input[i][1], input[i][2]));
        double error = fabs(integrate_left(funct_gauss,input[i][0], input[i][1], input[i][2])-solution[i]);
        if(error <= tolerance){
            passed++;
        }
        else{
            failed++;
            printf("Failed case 2.%d: Input: (funct_gauss, %f, %f, %f)\n",i+1,input[i][0], input[i][1], input[i][2]);
            printf("Error is %f, tolerance is %f\n\n",error, tolerance);
        }
    }
}

void test_differentiate(){
    printf("Testing differentiate...\n");
    double input[5][3] = {{0.0,h},{-1.0,h},{3.0,h},{-0.5,h}, {10.0,h}};
    double solution[5] = {3.0, 3.0, 3.0, 3.0, 3.0};
    for(int i = 0; i<5; i++){
        //printf("%f, ",integrate_left(funct_gauss,input[i][0], input[i][1], input[i][2]));
        double error = fabs(differentiate(funct_3x,input[i][0],input[i][1])-solution[i]);
        if(error <= tolerance){
            passed++;
        }
        else{
            failed++;
            printf("Failed case 3.%d: Input: (funct_3x, %f, %f)\n",i+1,input[i][0], input[i][1]);
            printf("Error is %f, tolerance is %f\n\n",error, tolerance);
        }
    }
}

void test_implementation(){
    printf("Testing implementation...\n");
    //Test if implementation is as specified
    double mid = integrate_midpoint(funct_3x, 0, 1, 0.3);
    double left = integrate_left(funct_3x, 0, 1, 0.3);
    double diff = differentiate(funct_gauss, 0, 0.3);
    if(fabs(mid - 1.5) < 0.000001){
        passed+=2;
    }
    else{
        printf("Failed case 4.1: integrate_midpoint does not yield exactly the expected result, therefore differs from definition in task (counts as 2 cases).");
        failed+=2;
    }
    if(fabs(left - 1.080000) < 0.00001){
        passed+=2;
    }
    else{
        printf("Failed case 4.2: integrate_left does not yield exactly the expected result, therefore differs from definition in task (counts as 2 cases).");
        failed+=2;
    }

    if(fabs(diff) < 0.00001){
        passed+=1;
    }
    else{
        printf("%f, Failed case 4.3: differentiate does not yield exactly the expected result, therefore differs from definition in task.",diff);
        failed+=1;
    }

}


int main(){
    test_integrate_midpoint();
    test_integrate_left();
    test_differentiate();
    test_implementation();

    printf("\n\nTOTAL SCORE: %d / % d\n",passed, passed+failed);
    printf("Please note that these testcases should only give you an orientation, and are NOT representative for the correction test cases.");
}