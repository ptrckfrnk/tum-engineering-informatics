
/*****************************************************************
* Name: Philipp Kaeß
* Course: MSE Informatik I
* Semester: WS19/20
* Homework 4: Matrix Calculations
* File: main_matrix.c
* File type: Testing for students
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "matrix_functions.c"

/*With this main-function you can test your results.
 * Therefore, simply run this main and enter a matrix
 * of your choice. The main will then create a struct
 * Tensor with your given attributes and run your
 * functions on this struct. The results are then
 * printed and have to be checked by you by hand.
 */
int main(){
    while(1) {
        printf("Please enter the dimension of your new matrix (1/2/3/4) or press 0 to quit: ");

        struct Tensor T;
        scanf("%d", &(T.dim));
        if (T.dim == 1) {
            printf("Element [0][0]: ");
            scanf("%d", &(T.M.A1[0][0]));
        } else if (T.dim == 2) {
            for (int i = 0; i < T.dim; i++) {
                for (int j = 0; j < T.dim; j++) {
                    printf("Element [%d][%d]: ", i, j);
                    scanf("%d", &(T.M.A2[i][j]));
                }
            }
        } else if (T.dim == 3) {
            for (int i = 0; i < T.dim; i++) {
                for (int j = 0; j < T.dim; j++) {
                    printf("Element [%d][%d]: ", i, j);
                    scanf("%d", &(T.M.A3[i][j]));
                }
            }
        } else if (T.dim == 4) {
            for (int i = 0; i < T.dim; i++) {
                for (int j = 0; j < T.dim; j++) {
                    printf("Element [%d][%d]: ", i, j);
                    scanf("%d", &(T.M.A4[i][j]));
                }
            }
        } else {
            return 0;
        }
        printf("The results of your calculations are printed:\n");
        printf("Determinant: %d\n", determinant(T));
        printf("Is Invertible: %d\n", is_invertible(T));
        printf("Determinant of Inverse: %f\n\n", inv_determinant(T));
        printf("Please check the printed results above for correctness.\n\n");
    }
}