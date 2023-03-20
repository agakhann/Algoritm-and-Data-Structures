//Problem 8.1(a)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int largest(int arr[], int n)
{
     
    int max = arr[0];
 
    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
 
    return max+1;
}


void countingSort(int arr[], int n){
    
    int max = largest(arr,n);
    int c[max];
    
    
    
    for(int i = 0; i < max;i++){
        c[i] = 0;
    }

    for(int j = 0; j < n; j++){
        c[arr[j]] = c[arr[j]] + 1;
    }

    for(int k = 1; k < max; k++){
        c[k] = c[k]+ c[k-1];
    }

    int sorted[n];
    
    for(int l = (n - 1); l >= 0; l--){
        sorted[c[arr[l]]] = arr[l];
        c[arr[l]] = c[arr[l]]-1;
    }

    for(int i = 0; i < n; i++){
        arr[i] = sorted[i+1];
    }
}

int main(){
    int arr[] = {9,1,6,7,6,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr,n);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}






