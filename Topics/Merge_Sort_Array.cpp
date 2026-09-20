// Merge Sort -> Divide & Conquer
//  USing recursion, first divide into 2 parts till st = end, and then merge

// TC: O(n log n)
// where
// log n = number of levels of division
// n = total work done by merge at each level

// SC: O(n) -> b/c we took temp vector of length n

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++)
    {
        arr[st + k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
        return;

    int mid = st + ((end - st) / 2);
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, st, mid, end);
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}