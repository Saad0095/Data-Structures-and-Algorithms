#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> cities(n);
        
        for (auto& road : roads) {
            cities[road[0]].push_back(road[1]);
            cities[road[1]].push_back(road[0]);
        }
        
        int maxR = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = cities[i].size() + cities[j].size();
                
                if (find(cities[i].begin(), cities[i].end(), j) != cities[i].end()) {
                    rank--;
                }
                
                maxR = max(maxR, rank);
            }
        }
        
        return maxR;
    }
};

int main(){
    
    return 0;
}