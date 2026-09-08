#include <bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>> matrix, int target)
{
    bool found = false;

    int m = matrix.size();    
    int n = matrix[0].size(); 
    int left = 0, right = m * n -1;
    while(left<=right){
        int mid = (left + right )/2;
        int midRow = mid / n;  
        int midCol = mid % n;
        if(matrix[midRow][midCol] == target){
            found = true;
            break;
        }
        else if(target > matrix[midRow][midCol]){
            left = mid + 1; 
        }
        else{
            right = mid - 1; 
        }
    }
    return found;
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 20;

    cout << search(matrix, target);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// bool search(vector<vector<int>> matrix, int target){
//     bool found = false;

    // int m = matrix.size();    // number of rows
    // int n = matrix[0].size(); // number of columns
//     for(int i=0; i < m;i++){
//         for(int j=0; j < n; j++){
//             if(target == matrix[i][j])
//                 found = true;
//         }
//     }
//     return found;
// };

// int main(){
//     vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//     int target = 20;

//     cout<< search(matrix,target);
//     return 0;
// }