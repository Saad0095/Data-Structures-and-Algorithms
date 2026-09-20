#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllSubets(vector<int>& nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getAllSubets(nums, ans, i + 1, allSubsets);  // include

        ans.pop_back();

        // Skipping duplicates
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

        getAllSubets(nums, ans, idx, allSubsets);  // exclude
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        sort(nums.begin(), nums.end()); // Sort the array first 
        
        getAllSubets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main(){
    
    return 0;
}