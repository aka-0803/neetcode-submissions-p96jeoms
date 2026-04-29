class Solution {
private:
    int solve(int ind,int sum, int total_sum, int target,vector<int>& nums,vector<vector<int>>& dp){
        int n = nums.size();
        if(ind==n){
            if(sum==target){
                return 1;
            }

            return 0;
        }

        if(dp[ind][sum+total_sum]!=INT_MIN){
            return dp[ind][sum+total_sum];
        }

        //add
        int add_cnt = solve(ind+1,sum+nums[ind],total_sum,target,nums,dp);
        //substract
        int sub_cnt = solve(ind+1,sum-nums[ind],total_sum,target,nums,dp);

        return  dp[ind][sum+total_sum] = add_cnt+sub_cnt;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums){
            sum += num;
        } 
        vector<vector<int>> dp(n,vector<int>(2 * sum + 1,INT_MIN));

        return solve(0,0,sum,target,nums,dp);
    }
};
