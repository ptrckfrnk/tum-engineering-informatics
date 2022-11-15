
/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 4: Numerical Integration
* File: funct_lib.c
* File type: Template File
*****************************************************************/

////////////////////DO NOT CHANGE ANYTHING IN THIS FILE!!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funct_lib.h"

double funct_3x(double x){
    return 3*x;
}

double funct_3(double x){
    return 3;
}

double funct_x2(double x){
    return pow(x,2);
}

double funct_x3(double x){
    return pow(x,3);
}

double funct_arclen(double x){
    return sqrt(1 + pow(cos(x),2));
}


double funct_gauss(double x){
    return exp(-(pow(x,2)));
}


