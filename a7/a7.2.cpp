// Problem 7.2(a)

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

int *LomotoP(int arr[], int l, int h){
    
    int pivot1 = arr[l];
    int pivot2 = arr[l+1];
    
    if(pivot1>pivot2){
        swap(arr[l],arr[l+1]);
        pivot1 = arr[l];
        pivot2 = arr[l+1];
    }
    
    swap(arr[l+1], arr[h]);

    int i = l;
    
    for(int j = l + 1;j <= h;j++){
        if(arr[j] <= pivot1){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    int pivot1Index = i;
    swap(arr[l],arr[i]);
    
    i++;
    
    swap(arr[i],arr[h]);
    pivot2 = arr[i];
    int temp = i;
    
    
    
    
    for(int k = temp + 1; k <= h; k++){
        if(arr[k] <= pivot2){
            i++;
            swap(arr[i],arr[k]);
        }
    }
    int pivot2Index = i;

    swap(arr[pivot1Index+1], arr[i]);

    static int pvt[2] = {pivot1Index,pivot2Index};

    return pvt;

}

void QuickSortL(int arr[], int l, int h){
    if(l<h){
        int *q;
        q = LomotoP(arr,l,h);
        QuickSortL(arr, l, q[0]-1);
        QuickSortL(arr, q[0]+1,q[1]-1);
        QuickSortL(arr, q[1], h);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSortL(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}