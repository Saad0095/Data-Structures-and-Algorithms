#include <bits/stdc++.h>
using namespace std;

// ** Bubble Sort (Opimized with flag) **
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping occurred, array is already sorted
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smIdx])
            {
                smIdx = j;
            }
        }
        swap(arr[i], arr[smIdx]);
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;        
    }

}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 1, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);

    printArr(arr, n);
    return 0;
}