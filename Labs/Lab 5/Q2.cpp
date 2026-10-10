#include<bits/stdc++.h>
using namespace std;

class Solution {
    queue<int> q;
public:
    int findTheWinner(int n, int k) {

        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        while(q.size() > 1){
            for(int j = 0; j < k - 1; j++){
                int frontFrd = q.front();
                q.pop();
                q.push(frontFrd);
            }
            q.pop();
        }
        return q.front();
    }
};

int main(){
    
    return 0;
}