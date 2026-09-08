#include <bits/stdc++.h>
using namespace std;

int search(vector<float> nums, float target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<float> nums = {5, 6, 7, 11, 12, 16};
    float target = 11;
    int index = search(nums,target);
    index == -1 ?  cout << "Element not found" :  cout<< "Elemenet is at index: " << index;
    return 0;
}