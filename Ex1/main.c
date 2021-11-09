#include <stdio.h>
#include "NumClass.h"


int main()
{
    int first,second;
    printf("Enter your first natural positive number :");
    scanf("%d",&first);
    printf("Enter your second natural positive number :");
    scanf("%d",&second);
    
    printf("Your Palindrom numbers are:");
    for(int i = first ; i <= second ; i++){
        if(isPalindrome(i)){
            printf(" %d",i);
        }
    }
    
    printf("\n");
    printf("Your Strong Numbers are:");
    for(int i = first ; i <= second ; i++){
        if(isStrong(i)){
            printf("%d",i);
        }
    }
    
    printf("\n");
    printf("Your Prime numbers are:");
    for(int i = first ; i <= second ; i++){
        if(isPrime(i)){
            printf("%d",i);
        }
    }
    
    printf("\n");
    printf("Your Armstrong numbers are:");
    for(int i = first; i <= second ; i++){
        if(isArmstrong(i)){
            printf("%d",i);
        }
    }

    printf("\n");
    return 0;
}