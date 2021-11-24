#include <stdio.h>
#include "my_mat.h"

int main(){
    char get;
    printf("Enter program type: ");
    scanf("%c", &get);
    int index1, index2;
    int matrix[10][10];
    
    while(get != 'D'){
        
        if(get == 'A'){
            printf("You've chose program A \n");
            A(matrix);
        }
    
        if(get == 'B'){
            printf("You've chose program B \n");
            scanf("%d %d", &index1, &index2);
            B(matrix, index1, index2);
            printf("\n");
        }
    
        if(get == 'C'){
            printf("You've chose program C \n");
            scanf("%d %d", &index1, &index2);
            C(matrix, index1, index2);
            printf("\n");
        }
        
        
        scanf("%c", &get);
    }
    printf("You've ended the program,please enter a new one: \n ");
}