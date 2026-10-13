#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx = st-1, pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if(arr[j]<= pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx-1);
        quickSort(arr, pivIdx + 1, end);
    }
}

int main(){
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);

    for (int a: arr){
        cout << a << "\t";
    }
    return 0;
}