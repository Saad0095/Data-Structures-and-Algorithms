#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j = digits.size() - 1;

        while (j >= 0 && digits[j] == 9) {
            digits[j] = 0;
            j--;
        }

        if (j >= 0) {
            digits[j]++;
        } else {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main(){
    
    return 0;
}