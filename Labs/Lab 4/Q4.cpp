#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool found(vector<vector<char>>& board, string& word, int r, int c, int idx) {
        
        if (idx == word.size()) return true;
        
        if (r < 0 || r >= board.size()) return false;
        if (c < 0 || c >= board[0].size()) return false;
        if (board[r][c] != word[idx]) return false;
        
        char temp = board[r][c];
        board[r][c] = '#';
        
        bool result = found(board, word, r+1, c, idx+1)
                    || found(board, word, r-1, c, idx+1)
                    || found(board, word, r, c+1, idx+1)
                    || found(board, word, r, c-1, idx+1);
        
        board[r][c] = temp;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                if (found(board, word, r, c, 0)) return true;
        
        return false;
    }
};

int main(){
    
    return 0;
}