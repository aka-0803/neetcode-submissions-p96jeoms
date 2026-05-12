class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minBuy = prices[0];
       int maxP = 0;
       for(int i=0;i<prices.size();i++){
            maxP = max(maxP,(prices[i]-minBuy));
            minBuy = min(minBuy,prices[i]);
       }

       return maxP;
    }
};
