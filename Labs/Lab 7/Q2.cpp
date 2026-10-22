#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSort(vector<int>& a) {
    int n = a.size();
    vector<int> temp(n);

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size;
            int right = min(left + 2 * size, n);

            int i = left, j = mid, k = left;

            while (i < mid && j < right) {
                if (a[i] <= a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while (i < mid)
                temp[k++] = a[i++];

            while (j < right)
                temp[k++] = a[j++];

            for (int p = left; p < right; p++)
                a[p] = temp[p];
        }
    }
}

int main() {
    vector<int> a = {8, 3, 5, 1, 9, 2, 7, 4};

    mergeSort(a);

    for (int x : a)
        cout << x << " ";

    return 0;
}
