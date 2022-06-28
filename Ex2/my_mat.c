#include <stdio.h>
#include "my_mat.h"

// finding the minimum -->
int minimum(int x, int y){
    if(x < y){
        return x;
    }
    else return y;
}


void find(int matrix [10][10]){
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            for(int k = 0 ; k < 10 ; k++){
                if(matrix[i][j] != 0 && matrix[i][k] != 0 && matrix[j][k] != 0){
                    matrix[j][k] = minimum(matrix[j][k] , matrix[i][j] + matrix[i][k]);
                }
                if(j != k && matrix[j][k] == 0 && matrix[i][j] != 0 && matrix[i][k] != 0){
                    matrix[j][k] = matrix[i][j] + matrix[i][k];
                }
            }
        }
    }
}

// here we are getting the data of each line and column of the matrix from the user 
void A (int matrix[10][10]){
    // int x; //new var
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
             scanf("%d", &matrix[i][j]);
                // scanf("%d",&x);
                // matrix[i][j] = x;
        }
    }
    find(matrix);
}

// getting the (i,j) from user and print TRUE if there is a path from i-->j
// else print FALSE
void B (int matrix[10][10], int index1, int index2){
    if(matrix[index1][index2] != 0){
        printf("True");
    }
    else printf("False");
}

// getting the (i,j) from user and printing the shortest path from i-->j
// if there is no such path print "-1"
void C (int matrix[10][10], int index1, int index2){
    if(matrix[index1][index2] != 0){
        printf("%d", matrix[index1][index2]);
    }
    else printf("-1");
}