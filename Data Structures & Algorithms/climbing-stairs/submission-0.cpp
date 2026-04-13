class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n==0) return 1;

        if(n<0) return 0;

        if(dp[n]!=-1){
            return dp[n];
        }

        int cnt_1 = 0;
        int cnt_2 = 0;

        if(n-1>=0){
            cnt_1 = solve(n-1,dp);
        }

        if(n-2>=0){
            cnt_2 = solve(n-2,dp);
        }

        return dp[n] = cnt_1+cnt_2;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        solve(n,dp);
        return dp[n];
    }
};
