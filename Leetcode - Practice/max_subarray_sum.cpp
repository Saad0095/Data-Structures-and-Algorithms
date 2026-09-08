#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ***  Sub array Concept

    // int n = 5;
    // int arr[n] = {1, 2, 3, 4, 5};

    // for (int st = 0; st < n; st++)
    // {
    //     for (int end = st; end < n; end++)
    //     {
    //         for (int i = st; i <= end; i++)
    //         {
    //             cout << arr[i];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    //  *** Maximum Sub array SUM (Brute Force) On^3
    
    // int n = 5, max= INT_MIN;
    // int arr[n] = {1, -2, 3, 4, -5};
    // int maxSt = 0 ,maxEnd=0;
    // for (int st = 0; st < n; st++)
    // {
    //     for (int end = st; end < n; end++)
    //     {
    //         int sum = 0;
    //         for (int i = st; i <= end; i++)
    //         {
    //             sum += arr[i];
    //         }
    //         if (sum > max){
    //             max = sum;
    //             maxSt = st;
    //             maxEnd = end;
    //         }
    //     }
    // }
    // cout<< "Maximum Sum: " << max << endl;
    // cout<< "Maximum Sub Arr: " << endl;

    // for (int i = maxSt; i<= maxEnd; i++){
    //     cout << arr[i] << " "; 
    // }


    //  *** Maximum Sub array SUM (Brute Force) On^2
    
    // int n = 7, maxSum= INT_MIN;
    // int arr[n] = {3, -4, 5, 4, -1, 7, -8};
    // for (int st = 0; st < n; st++)
    // {
    //     int sum = 0;
    //     for (int end = st; end < n; end++)
    //     {
    //         sum+= arr[end];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // cout<< "Maximum Sum: " << maxSum << endl;


    //  *** Maximum Sub array SUM (Kadane's Algorithm) O(n) <- Most Optimized <- Dynamic arr problem

    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};

    int currentSum = 0, maxSum = INT_MIN;
    for(int val : nums){
            currentSum += val;
        maxSum = max(currentSum, maxSum);
        if(currentSum < 0){
            currentSum = 0;
        }
    }
    return 0;
}