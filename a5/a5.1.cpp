//Problem 5.1 (a)
#include <iostream>
#include <cmath>

using namespace std;

int naiveAlg(int n){
    if(n < 2){
        return n;
    }
    else{
        return (naiveAlg(n-1) + naiveAlg(n-2))
    }  
}

int bottomUp(int n){
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    
    for (int i = 2; i <= n; i++){
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    
    return arr[n];
}

int closedForm(int n){
    float F = (1+ sqrt(5))/2.0
    return ((pow(F,n)) / sqrt(5))
}

int matrix(int n)
{
    int arr[2][2];
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 0;
    int Mult[2][1];
    Mult[0][0] = 0;
    Mult[1][0] = 1;
    int temp1;
    int temp2;
    for (int i = 0; i < n; i++)
    {
        temp1 = Mult[0][0];
        temp2 = Mult[1][0];
        Mult[0][0] = arr[0][0] * temp1 + arr[0][1] * temp2;
        Mult[1][0] = arr[1][0] * temp1 + arr[1][1] * temp2;
    }

    return Mult[0][0];
}