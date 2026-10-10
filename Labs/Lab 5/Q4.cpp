#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    vector<int> nums;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        int n = nums.size();
        for(int j = n - 1; j >= n - k; j--){
            product *= nums[j];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main(){
    
    return 0;
}