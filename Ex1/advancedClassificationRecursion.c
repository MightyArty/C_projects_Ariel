#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int isPalindromeRec(int n, int k){
    if(n == 0)
        return k;

    k = k * 10;
    k = k + (n % 10);
    return isPalindromeRec(n/10,k);
}

int isPalindrome(int n){
     if(n == isPalindromeRec(n,0))
         return 1;
    return 0;
}

int isArmstrongRec(int n,int p){
    if(n > 0)
        return (pow(n%10,p) + isArmstrongRec(n/10,p));
    else
        return 0;
}

int isArmstrong(int n){
    if(n == isArmstrongRec(n,(int)log10(n) +1))
     return 1;
    else
     return 0;
}