
/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 1:N-th partial sum
* File: partial_sum.c
* File type: Template file
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>


/**
* calc_h
*
* This function calculates the n-th partial sum of the harmonic series
*
*
* @param n number of partials (assume n>=0)
*
* @return n-th partial sum of harmonic series H(n)
*/
double calc_h(int n){
    //Your code starts here
    double sum = 0;
    int count;

    for (count = 1; count <= n; count++) {
      sum += 1.0 / count;
    }

    return sum;

    //End of your code
}



/**
* calc_n
*
* This function calculates the smallest n, for which the n-th
* partial sum of the harmonic series is larger than or equal to the input h
*
*
* @param h input h (assume h >=0)
*
* @return smallest n, with H(n) >= h
*/
int calc_n(double h){
    //Your code starts here
    double sum = 0;
    int n = 0;

    while (sum < h) {
      n++;
      sum += 1.0 / n;
    }

    return n;

    //End of your code
}
