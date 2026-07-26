class Solution {
public:
    int helper(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        
        if(amount==0) return 1;
        if(ind>=coins.size()) return 0;

       
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int ans = 0;
        if(amount>=coins[ind]){
            ans = helper(ind+1,amount,coins,dp);
            ans += helper(ind,amount-coins[ind],coins,dp);
        }

        return dp[ind][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,dp);
    }
};