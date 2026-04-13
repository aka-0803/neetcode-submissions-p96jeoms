class Solution {
private:
    int solve(int ind,int n, vector<int>& cost,vector<int>& dp){
        if(ind>=n){
            return 0;
        }

        if(dp[ind]!=-1) return dp[ind];

        int step_1 = cost[ind]+solve(ind+1,n,cost,dp);
        int step_2 = cost[ind]+solve(ind+2,n,cost,dp);

        return dp[ind] = min(step_1,step_2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n==2){
            return min(cost[0],cost[1]);
        }

        vector<int> dp(n,-1);

        solve(0,n,cost,dp);
        solve(1,n,cost,dp);

        return min(dp[0],dp[1]);
    }
};
