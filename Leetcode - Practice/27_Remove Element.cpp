class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int i =0; i< k; i++){
            while(i<k && nums[i] == val){
                swap(nums[i], nums[k-1]);
                k--;
            }
        }
        return k;
    }
};

// Two Pointer Approach

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i =0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};