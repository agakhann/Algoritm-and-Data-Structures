#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void selesctionSort(int arr[], int n){
    int temp = 0;
    
    for(int i = 0; i < n-1; i++){
        int min = i;
        
        for(int j = i; j < n; j++){
            if(arr[min]>arr[j])
                min = j;
        }
        
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}