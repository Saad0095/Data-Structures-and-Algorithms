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
        getAllSubets(nums, ans, i + 1, allSubsets);  // exclude
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main(){
    
    return 0;
}