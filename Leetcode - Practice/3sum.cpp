// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> arr;

//         for (int i = 0; i < nums.size(); i++) {

//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;

//             for (int j = i + 1; j < nums.size(); j++) {

//                 if (j > i + 1 && nums[j] == nums[j - 1])
//                     continue;

//                 for (int k = j + 1; k < nums.size(); k++) {

//                     if (k > j + 1 && nums[k] == nums[k - 1])
//                         continue;

//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         arr.push_back({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }

//         return arr;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};