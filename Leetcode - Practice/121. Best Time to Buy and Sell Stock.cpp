
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  lowest = INT_MAX,profit = 0;
        for(int i =0; i< prices.size(); i++){
            int possible_profit = 0;
            if(prices[i] < lowest){
                lowest = prices[i];
                continue;
            }

           possible_profit = prices[i] - lowest;
            if (possible_profit > profit){
                profit = possible_profit;
            }
        }
        return profit;

    }
};


// Better version


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  lowest = INT_MAX,profit = 0;
        for (int price: prices){
            lowest = min(lowest, price);
            profit = max(profit, price- lowest);
        }
        return profit;

    }
};
