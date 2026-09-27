class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int len = 1;
         int maxLen = 1;
         int prev = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev)continue;
            if(nums[i]-prev==1){
                len++;
            }else{
                len = 1;
            }
            prev = nums[i];
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};
