#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int singlenumber(vector<int>& nums){
            int ans = 0;
            for(int val: nums){
//              a ^ a = 0
//              a ^ 0 = a
                ans ^= val;
                cout << ans << endl;
            }
            return ans;
        }
};

int main(){
    Solution s1;
    vector<int> nums = {4,4,2,3,3};
    int ans = s1.singlenumber(nums);
    cout << "Ans: " << ans;
}