#include <bits/stdc++.h>
using namespace std;

class Sort{
    vector<int> arr;

    void bubbleSort(vector<int>& a, int& comparisons, int& swaps){
        for(int i = 0; i < (int)a.size() - 1; i++){
            for(int j = 0; j < (int)a.size() - i - 1; j++){
                comparisons++;
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                    swaps++;
                }
            }
        }
    }

    void insertionSort(vector<int>& a, int& comparisons, int& swaps){
        for(int i = 1; i < (int)a.size(); i++){
            int key = a[i];
            int j = i - 1;

            while(j >= 0){
                comparisons++;
                if(a[j] <= key)
                    break;
                a[j + 1] = a[j];
                swaps++;
                j--;
            }
            a[j + 1] = key;
        }
    }

    void selectionSort(vector<int>& a, int& comparisons, int& swaps){
        for(int i = 0; i < (int)a.size() - 1; i++){
            int minimum = i;
            for(int j = i + 1; j < (int)a.size(); j++){
                comparisons++;
                if(a[j] < a[minimum])
                    minimum = j;
            }
            if(minimum != i){
                swap(a[i], a[minimum]);
                swaps++;
            }
        }
    }

public:
    Sort(vector<int> values){
        arr = values;
    }

    void sortUsing(string choice){
        int type;
        if(choice == "bubble")
            type = 1;
        else if(choice == "insertion")
            type = 2;
        else if(choice == "selection")
            type = 3;
        else{
            cout << "Invalid sorting technique." << endl;
            return;
        }

        int comparisons = 0;
        int swaps = 0;

        if(type == 1)
            bubbleSort(arr, comparisons, swaps);
        else if(type == 2)
            insertionSort(arr, comparisons, swaps);
        else
            selectionSort(arr, comparisons, swaps);

        cout << "Sorted array: ";
        for(int value : arr)
            cout << value << " ";
        cout << endl;
    }

    void analyze(int n){
        vector<int> randomArray(n);
        for(int& value : randomArray)
            value = rand() % 100;

        string names[3] = {"Bubble", "Insertion", "Selection"};
        int operations[3];

        for(int i = 0; i < 3; i++){
            vector<int> copy = randomArray;
            int comparisons = 0;
            int swaps = 0;

            if(i == 0)
                bubbleSort(copy, comparisons, swaps);
            else if(i == 1)
                insertionSort(copy, comparisons, swaps);
            else
                selectionSort(copy, comparisons, swaps);

            operations[i] = comparisons + swaps;

            cout << names[i] << " - Comparisons: " << comparisons
                 << ", Swaps: " << swaps << endl;
        }

        int best = 0;
        int worst = 0;
        for(int i = 1; i < 3; i++){
            if(operations[i] < operations[best])
                best = i;
            if(operations[i] > operations[worst])
                worst = i;
        }

        cout << "Best technique: " << names[best] << endl;
        cout << "Worst technique: " << names[worst] << endl;
    }
};

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter elements: ";
    for(int& value : values)
        cin >> value;

    string choice;
    cout << "Enter technique (bubble/insertion/selection): ";
    cin >> choice;

    Sort sorting(values);
    sorting.sortUsing(choice);

    int analysisSize;
    cout << "Enter size for random analysis: ";
    cin >> analysisSize;
    sorting.analyze(analysisSize);

    return 0;
}
