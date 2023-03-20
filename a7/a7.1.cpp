#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

int LomotoP(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l;
    int j = l + 1;
    
    for(j = l + 1;j <= h;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[i]);
    return i;
}

int HoareP(int arr[],int l, int h){
    int pivot = arr[l];
    int i = l-1;
    int j = h+1;

    while(i<j){

        do{
            i++;
        }while (arr[i] < pivot);

        do{
            j--;
        }while (arr[j]>pivot);

        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}

int median(int arr[],int l, int h){
    int mid = (l + h)/2;
    
    if(arr[h] < arr[l])
        swap(arr[l],arr[h]);        
    
    if(arr[mid] < arr[l])
        swap(arr[mid],arr[l]);
    
    if(arr[h] < arr[mid])
        swap(arr[h],arr[mid]);

    swap(arr[mid],arr[l]);

    return HoareP(arr,l,h);
} 


void QuickSortL(int arr[], int l, int h){
    if(l<h){
        int q = LomotoP(arr,l,h);
        QuickSortL(arr, l, q-1);
        QuickSortL(arr, q+1,h);
    }
}

void QuickSortH(int arr[], int l, int h){
    if(l<h){
        int q = HoareP(arr,l,h);
        QuickSortH(arr, l, q-1);
        QuickSortH(arr, q+1,h);
    }
}

void QuickSortM(int arr[], int l, int h){
    if(l<h){
        int q = median(arr,l,h);
        QuickSortM(arr, l, q-1);
        QuickSortM(arr, q+1, h);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    int arr[1000];
    int n = sizeof(arr)/sizeof(arr[0]);
    
    srand (time(NULL));
    
    clock_t beginL, endL;
    clock_t beginH, endH;
    clock_t beginM, endM;
    
    double time_spentL = 0;
    double time_spentH = 0;
    double time_spentM = 0;
         
    for(int i = 0;i<100000;i++){
        int temp [1000];
        
        for(int j = 0; j<1000;j++){
            temp[j] = rand();
        }
        
        beginL = clock();
        QuickSortL(temp, 0, n-1);
        endL = clock();
        
        double Ltime = (double)(endL-beginL);
        time_spentL += Ltime;

        beginH = clock();
        QuickSortH(temp,0,n-1);
        endH = clock();
        
        double Htime = (double)(endH-beginH);
        time_spentH += Htime;

        beginM = clock();
        QuickSortM(temp,0,n-1);
        endM = clock();
        
        double Mtime = (double)(endM-beginM);
        time_spentM += Mtime;
    }
    
    cout << "Lomoto: "<< time_spentL / CLOCKS_PER_SEC << endl;
    cout << "Hoare: "<< time_spentH / CLOCKS_PER_SEC << endl;
    cout << "Median-of-three: "<< time_spentM / CLOCKS_PER_SEC << endl;
    //printf("Sorted array: \n");
    //printArray(arr, n);
    return 0;
}