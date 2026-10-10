#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cout << "Enter number of toys and amount: ";
    cin >> n >> k;

    int* arr = new int[n];
    cout << "Enter toy costs: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int total = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(total + arr[i] > k)
            break;
        total += arr[i];
        count++;
    }

    cout << "Maximum number of toys: " << count << endl;

    delete[] arr;
    return 0;
}
