class Solution {
public:
    
    int helper(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;

        if(dp[amount]!=-1){
            return dp[amount];
        }
        int res = INT_MAX;
        for(int coin : coins){
            if(amount-coin>=0){
                int result = helper(coins,amount-coin,dp);
                if(result!=INT_MAX){
                    res = min(1+result,res);
                }
            }
        }

        return dp[amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,-1);
        helper(coins,amount,dp);
        return dp[amount] == INT_MAX ? -1 : dp[amount];

    }
};
