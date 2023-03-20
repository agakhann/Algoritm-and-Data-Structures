//Problem 6.2 (b)

#include <iostream>

using namespace std;

void maxHeapify(int A[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && A[l] > A[largest])
        largest = l;
    else 
        largest = i;
    
    if(r < n && A[r] > A[largest])
        largest = r;

    if(largest != i){
        swap(A[i],A[largest])
        maxHeapify(A, n, largest);
    }
}

void buildMaxHeap(int A[],int n){
    for( int i = n/2; i > 1; i--){
        maxHeapify(A, n,i);
    }
}

int pushDown(int[A],int n,int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l >= n){
        return i;
    }
    else if(r >= n){
        swap(A[l],A[i]);
        return l;
    }
    else{
        
        if(A[l] > A[r]){
            swap(A[l],A[i]);
            largest = l;
        }
        else{
            swap(A[r],A[i]);
            largest = r;
        }   
    }
    
    return pushDown(A,n,parent);
}

void pushUp(int A[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (A[parent] < A[i])
    {
        swap(A[root],A[parent]);
        pushUp(A, n, i);
    }
}

void HeapSort(int A[], int n){
    buildMaxHeap(A[],n);
    for(i = n-1;i > 2; i--){
        swap(A[1],A[i]);
        n -= 1;
        int p = pushDown(A , n, 0);
        pushUp(A, n, p);
    }
}
