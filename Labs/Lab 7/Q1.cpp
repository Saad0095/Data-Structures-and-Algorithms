
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[high]);
    return i;
}

void quickSort(vector<int>& a) {
    if (a.size() <= 1)
        return;

    stack<int> s;

    s.push(0);
    s.push(a.size() - 1);

    while (!s.empty()) {
        int high = s.top();
        s.pop();

        int low = s.top();
        s.pop();

        if (low >= high)
            continue;

        int p = partition(a, low, high);

        if (p - 1 > low) {
            s.push(low);
            s.push(p - 1);
        }

        if (p + 1 < high) {
            s.push(p + 1);
            s.push(high);
        }
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1};
    quickSort(arr);
    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
