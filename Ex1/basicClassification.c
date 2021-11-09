#include "NumClass.h"

//
int isPrime(int n) {
    if(n < 2){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    for(int i = 2 ; i < n ; i++){
        if(n % i == 0){
            return 0;
        }
    }
    
    return 1;
}

int isStrong(int n){
    int res = 0;
    int i = 0;
    int tmp = n;
    int arr[9];
    for(;i<10;i++){
        int j;
        arr[i] = 1;
        for(j = 2;j<=i;j++){
            arr[i] *= j;
        }
    }
    while(n > 0){
        int digit = n % 10;
        res += arr[digit];
        
        n = n / 10;
    }
    if(res == tmp)
        return 1;
    return 0;
}