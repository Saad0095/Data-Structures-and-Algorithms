#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    vector<double> nums;

public:
    void addNum(double n)
    {
        auto pos = lower_bound(nums.begin(),nums.end(), n);
        nums.insert(pos, n);
    }

      double findMedian()  {
        int s = nums.size();
        // sort(nums.begin(), nums.end());
        if(s % 2 == 0){
            double median = (nums[s/2 -1] + nums[s/2])/2; 
            return median; 
        }
        else{
            double median = nums[nums.size()/2];
            return median;
        }
    }
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0

    return 0;
}