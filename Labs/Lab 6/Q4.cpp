#include<bits/stdc++.h>
using namespace std;

vector<int> pancakeSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;

    for (int i = n; i > 1; i--) {
        int maxIdx = max_element(arr.begin(), arr.begin() + i) - arr.begin();

        if (maxIdx == i - 1) {
            continue;
        }

        if (maxIdx != 0) {
            reverse(arr.begin(), arr.begin() + maxIdx + 1);
            ans.push_back(maxIdx + 1);
        }

        reverse(arr.begin(), arr.begin() + i);
        ans.push_back(i);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 2, 4, 1};

    vector<int> flips = pancakeSort(arr);

    cout << "Flip sizes: ";
    for (int k : flips) {
        cout << k << " ";
    }

    cout << "\nSorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
