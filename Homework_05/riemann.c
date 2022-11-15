/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 4: Numerical Integration
* File: riemann.c
* File type: Template File
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "riemann.h"


/**
* differentiate
*
* This function calculates the slope of a function at a given point
* according to the symmetric difference quotient
*
* MEMORY : <important notes >
*
* @param f(x) is the function to integrate
* @param x is the point where the slope should be calculated
* @param h is the step size for the difference quotient
*
* @return the value of the calculated slope as double
*/
double differentiate(double (*f)(double x),double x,double h){
    ////YOUR CODE BEGINS HERE

    double SDQ = 0;
    SDQ = (f(x+h) - f(x-h)) / (2*h);
    return SDQ;

    ////YOUR CODE ENDS HERE
}



/**
* integrate_left
*
* This function calculates the integral of a function by the left rule
*
* MEMORY : <important notes >
*
* @param f(x) is the function to integrate
* @param a is the lower integration boundary
* @param b is the higher integration boundary
* @param h is the step size for numerical integration
*
* @return the value of the calculated integral as double
*/
double integrate_left(double (*f)(double x), double a, double b, double h){
    if(b<=a){
        printf("Invalid integration boundaries!\n");
        return 0;
    }
    double integral = 0;

    ////YOUR CODE BEGINS HERE

    int units = (b-a) / h;
    double s = b - (a + units*h);

    for (int i = 0; i < units; i++) {
        integral += h * f(a + i*h);
    }

    integral += s * f(a + units*h);

    ////YOUR CODE ENDS HERE

    return integral;
}


/**
* integrate_midpoint
*
* This function calculates the integral of a function by the midpoint rule
*
* MEMORY : <important notes >
*
* @param f(x) is the function to integrate
* @param a is the lower integration boundary
* @param b is the higher integration boundary
* @param h is the step size for numerical integration
*
* @return the value of the calculated integral as double
*/
double integrate_midpoint(double (*f)(double x), double a, double b, double h){
    if(b<=a){
        printf("Invalid integration boundaries!\n");
        return 0;
    }
    double integral = 0;

    ////YOUR CODE BEGINS HERE

    int units = (b-a) / h;
    double s = b - (a + units*h);

    for (int i = 0; i < units; i++) {
        integral += h * f(a + (i + 0.5)*h);
    }

    integral += s * f(a + units*h + s/2);

    ////YOUR CODE ENDS HERE

    return integral;
}



