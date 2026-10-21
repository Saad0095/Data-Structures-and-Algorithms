#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    int l = 0, r = n-1, go= 0;
    while(l<=r){
        if(l< r && arr[l] + arr[r] <= x) l++;
        r--;
        go++;
    }
    cout <<go << '\n';
    return 0;
}