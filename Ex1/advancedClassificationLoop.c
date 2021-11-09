#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int isPalindrome(int n ){
     int arr[10];
     int i =0;
     int j;
    while(n > 0){
        int digit = n % 10;
        arr[i++] = digit;
        n = n/10;
    }
    for(j = 0 ; j < i ; j++){
        if(arr[j] != arr[i-j-1]){
            return 0;
        }
    }
    return 1;
}

int isArmstrong(int n){
    int res =0;
    int tmp = n;
    int counter = 0;
    int length = (int)log10(n) +1;
    while(n > 0){
        counter++;
        n = n/10;
    }

    //initiallize again
    n = tmp;
    while(n > 0)
    {
        int digit = n % 10;
        res = res + pow(digit, length);
        n = n/10;
    }
    if(tmp == res){
        return 1;
     }
    return 0;
}