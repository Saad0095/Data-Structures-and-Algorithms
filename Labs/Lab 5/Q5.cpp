#include<bits/stdc++.h>
using namespace std;

class DataStream {
    int val;
    int cond;
    int count;
public:
    DataStream(int value, int k) {
        val = value;
        cond = k;
        count= 0;
    }
    
    bool consec(int num) {
        if(num != val){
            count = 0;
        }else{
            count++;
        }
        return count >= cond;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main(){
    
    return 0;
}