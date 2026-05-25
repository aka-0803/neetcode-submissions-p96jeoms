class Solution {
private:
    bool solve(int ind,int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }

        if(ind==0){
            return target==nums[ind] ? 1 : 0;
        }

        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        bool notTaken = solve(ind-1,target,nums,dp);
        bool taken = false;
        if(nums[ind]<=target){
            taken = solve(ind-1,target-nums[ind],nums,dp);
        }

        return dp[ind][target] = (notTaken || taken);
    }
public:
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for(auto num : nums){
            totSum += num;
        }

        if(totSum % 2 != 0){
            return false;
        }

        int target = totSum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};
