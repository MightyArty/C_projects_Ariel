#include <stdio.h>
#include "my_mat.h"

int main(){
    char get;
    scanf("%c", &get);
    int index1, index2;
    int matrix[10][10];
    
    while(get != 'D'){
        
        if(get == 'A'){
            A(matrix);
            
        }
    
        if(get == 'B'){
           
            scanf("%d %d", &index1, &index2);
            B(matrix, index1, index2);
            printf("\n");
        }
    
        if(get == 'C'){
            
            scanf("%d %d", &index1, &index2);
            C(matrix, index1, index2);
            printf("\n");
        }
        
        
        scanf("%c", &get);
    }

    
    
}