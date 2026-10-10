#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int mid = 0, low = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter colors using 0, 1, and 2: ";
    for (int &value : nums)
        cin >> value;

    sortColors(nums);

    cout << "Sorted colors: ";
    for (int value : nums)
        cout << value << " ";
    cout << endl;

    return 0;
}
