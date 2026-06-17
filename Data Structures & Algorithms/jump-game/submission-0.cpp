class Solution {
   public:
    bool helper(int ind, vector<int>& nums, vector<int>& dp) {
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int jumps = nums[ind];
        if (jumps == 0) {
            if (ind == nums.size() - 1) {
                dp[ind] = 1;
                return true;
            }
            return false;
        }

        int n = nums.size();
        int len = ind + jumps;
        if (len >= n - 1) {
            dp[ind] = 1;
            return true;
        }
        bool ans = false;
        for (int i = 1; i <= jumps; i++) {
            int newInd = i + ind;
            if (newInd < n) {
                ans = ans || helper(newInd, nums, dp);
            }
        }

        dp[ind] = ans == true ? 1 : -1;

        return ans;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};
