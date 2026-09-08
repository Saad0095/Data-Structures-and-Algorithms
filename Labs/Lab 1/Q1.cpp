#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 3, M =4;
    int** d2arr = new int*[N];

    int vals[3][4] = { {1,  2,  3,  4},
                   {5,  6,  7,  8},
                   {9, 10, 11, 12} };

    for(int i =0; i< N; i++){
        d2arr[i] = new int[M];
        for(int j =0; j < M; j++){
            d2arr[i][j] = vals[i][j];
        }
    }

    cout << "2d arr: " ;
    for(int i =0; i< N; i++){
        for(int j =0; j < M; j++){
            cout << d2arr[i][j] << " ";
        }
        cout << ", " ;
    }
    
    cout << endl;
    
    int* d1arr = new int[N*M];
    int index=0;
    for (int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++){
            d1arr[index++] = d2arr[j][i];
        }
    }
    
    cout << "1d arr: " ;
    for(int i = 0; i < N*M; i++){
        cout << d1arr[i] << " ";
    }
    
    for (int i = 0; i < N; i++)
    {
        delete[] d2arr[i];
    }
    
    delete[] d1arr;

    return 0;
}