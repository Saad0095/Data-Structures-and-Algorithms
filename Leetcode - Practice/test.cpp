#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = arr[i - 1] + x;
    }

    while (q > 0) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
        q--;
    }

    return 0;
}