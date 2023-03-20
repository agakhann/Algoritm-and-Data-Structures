#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Bucketsort(vector<int>& arr, int power)
{

    if (power == 0) {
        return;
    }
    else {
        vector<int> bucket[10];
        for (int i = 0; i < arr.size(); i++) {
            int pos = (arr[i] / power) % 10;
            bucket[pos].push_back(arr[i]);
        }
        for (int i = 0; i < 10; i++) {
            if (bucket[i].size() > 1) {
                Bucketsort(bucket[i], power / 10);
            }
        }
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

void Radixsort(vector<int>& arr)
{

    int maxnum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[0] < arr[i]) {
            maxnum = arr[i];
        }
    }
    int power = 1;
    while (maxnum / power > 10) {
        power = power * 10;
    }

    Bucketsort(arr, power);
}

int main(){
    vector<int> arr= {917,123,621,742,612,244,129};
    int n = sizeof(arr)/sizeof(arr[0]);
    Radixsort(arr);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}