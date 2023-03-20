// Problem 4.1(a)

#include <iostream>

using namespace std;

void merge(int arr[], int l , int r, int m){
    int left = m - l +1;
    int right = r - m;

    int L[left], R[right];

    
    for(int i = 0; i < left; i++){
        L[i] = arr[l+i];
    }
    for(int j = 0; j<right ;j++){
        R[j] = arr[m + 1 + j];
    }

    int i =0;
    int j =0;
    int k = l;

    while(i < left && j < right){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < left){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < right){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void insertionSort(int arr[], int l, int r){
    
    int i, key, j;
    
    for (i = l + 1; i <= r; i++){
        key = arr[i];
        j = i - 1;

        while (j >= l && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int l, int r, int k)
{
    if ((r - l) <= k)
    {
        insertionSort(arr, l, r);
    }
    else
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, k);
        mergeSort(arr, m + 1, r, k);
        merge(arr, l, m, r);
    }
}