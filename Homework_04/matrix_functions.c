/*****************************************************************
* Name: Patrick Franke
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 4: Matrix Calculations
* File: matrix_functions.c
* File type: Template for students
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

union Matrix{
    int A4[4][4];
    int A3[3][3];
    int A2[2][2];
    int A1[1][1];
};
struct Tensor{
    union Matrix M;
    int dim;
};

/**
* determinant
*
* This function calculates the determinant of a square int matrix from size 1x1 to 4x4
*
* MEMORY : <important notes >
*
* @param T contains a struct Tensor for the calculation
*
* @return an int that is the determinant of the matrix stored in T
*/
int determinant(struct Tensor T){

    if(T.dim == 1){
        return T.M.A1[0][0];
    }
    else if(T.dim == 2){
        return (T.M.A2[0][0] * T.M.A2[1][1])-(T.M.A2[1][0] * T.M.A2[0][1]);
    }
    else if(T.dim == 3){
        //YOUR CODE STARTS HERE
        int sum = 0;
        int v = 0;
        int i = 1;
        int j = 2;
        int pow = 1;

        for (v = 0; v < 3; v++) {
            if (v % 2 == 0) {
                pow = 1;
            } else if (v % 2 == 1) {
                pow = -1;
            }

            sum += pow * T.M.A3[0][v] * ((T.M.A3[1][i] * T.M.A3[2][j]) - (T.M.A3[2][i] * T.M.A3[1][j]));

            switch (v) {
                case 0:
                    i = 0;
                    break;
                case 1:
                    j = 1;
                    break;
                default:
                    i = 1;
                    j = 2;
            }
        }

        return sum;
        //YOUR CODE ENDS HERE
    }
    else if(T.dim == 4){
       //YOUR CODE STARTS HERE

       return T.M.A4[0][0] * (T.M.A4[1][1]*T.M.A4[2][2]*T.M.A4[3][3]+T.M.A4[1][2]*T.M.A4[2][3]*T.M.A4[3][1]+T.M.A4[1][3]*T.M.A4[2][1]*T.M.A4[3][2]-T.M.A4[1][3]*T.M.A4[2][2]*T.M.A4[3][1]-T.M.A4[1][2]*T.M.A4[2][1]*T.M.A4[3][3]-T.M.A4[1][1]*T.M.A4[2][3]*T.M.A4[3][2])
       - T.M.A4[0][1] * (T.M.A4[1][0]*T.M.A4[2][2]*T.M.A4[3][3]+T.M.A4[1][2]*T.M.A4[2][3]*T.M.A4[3][0]+T.M.A4[1][3]*T.M.A4[2][0]*T.M.A4[3][2]-T.M.A4[1][3]*T.M.A4[2][2]*T.M.A4[3][0]-T.M.A4[1][2]*T.M.A4[2][0]*T.M.A4[3][3]-T.M.A4[1][0]*T.M.A4[2][3]*T.M.A4[3][2])
       + T.M.A4[0][2] * (T.M.A4[1][0]*T.M.A4[2][1]*T.M.A4[3][3]+T.M.A4[1][1]*T.M.A4[2][3]*T.M.A4[3][0]+T.M.A4[1][3]*T.M.A4[2][0]*T.M.A4[3][1]-T.M.A4[1][3]*T.M.A4[2][1]*T.M.A4[3][0]-T.M.A4[1][1]*T.M.A4[2][0]*T.M.A4[3][3]-T.M.A4[1][0]*T.M.A4[2][3]*T.M.A4[3][1])
       - T.M.A4[0][3] * (T.M.A4[1][0]*T.M.A4[2][1]*T.M.A4[3][2]+T.M.A4[1][1]*T.M.A4[2][2]*T.M.A4[3][0]+T.M.A4[1][2]*T.M.A4[2][0]*T.M.A4[3][1]-T.M.A4[1][2]*T.M.A4[2][1]*T.M.A4[3][0]-T.M.A4[1][1]*T.M.A4[2][0]*T.M.A4[3][2]-T.M.A4[1][0]*T.M.A4[2][2]*T.M.A4[3][1]);

        //YOUR CODE ENDS HERE
    }
    else{
        printf("Invalid dimension!\n");
        return -1111;
    }
}

/**
* is_invertible
*
* This function determines whether the matrix stored in T is invertible or not
*
* MEMORY : <important notes >
*
* @param T contains a struct Tensor for the calculation
*
* @return 0 = not invertible, 1 = invertible
*/
int is_invertible(struct Tensor T){
    //YOUR CODE STARTS HERE

    int det = determinant(T);

    if (det == 0) {
        return 0;
    } else {
        return 1;
    }

    //YOUR CODE ENDS HERE
}


/**
* inv_determinant
*
* This calculates the inverse determinant of a square int matrix from size 1x1 to 4x4 if the matrix is invertible
*
* MEMORY : <important notes >
*
* @param T contains a struct Tensor for the calculation
*
* @return a float that is the determinant of the inverse of the matrix stored in T. If this matrix is not invertible, it returns 0
*/
float inv_determinant(struct Tensor T){
    //YOUR CODE STARTS HERE

    int inv = (float) is_invertible(T);

    if (inv == 0) {
        return 0.0;
    } else {
        return 1.0 / determinant(T);
    }

    //YOUR CODE ENDS HERE
}
