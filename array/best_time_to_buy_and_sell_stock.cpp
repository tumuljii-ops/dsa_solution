class Solution {
public:
    int maxProfit(vector<int>& prices) {
                 
        int cost = INT_MAX;
        int profit = 0;

        int i = 0;
        int j = 0;
        int n = prices.size();

        while(j < n){

            if(prices[j] < cost){
                cost = prices[j];
            }

            if(prices[j] > cost){
                profit = max(profit, prices[j] - cost);
            }

            j++;
        }
                 
        return profit;
    }
};