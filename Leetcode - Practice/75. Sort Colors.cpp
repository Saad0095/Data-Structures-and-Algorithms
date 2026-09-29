#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // BRUTE FORCE
        // sort(nums.begin(), nums.end()); // O(n log n)

        // Optimized => 2 passes => O(n)
        // int n = nums.size();
        // int count0 = 0, count1 = 0, count2 = 0;
        // for(int i = 0; i< n; i++){
        //     if (nums[i] == 0) count0++;
        //     else if (nums[i] == 1) count1++;
        //     else if (nums[i] == 2) count2++;
        // }

        // int idx = 0;
        // for(int i = 0; i < count0; i++){
        //     nums[idx++] = 0;
        // }
        // for(int i = 0; i < count1; i++){
        //     nums[idx++] = 1;
        // }
        // for(int i = 0; i < count2; i++){
        //     nums[idx++] = 2;
        // }


        // ** Dutch National Algorithm => 1 pass => SC = O(1) => TC = O(n)
         int mid = 0, low = 0, high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

int main()
{

    return 0;
}