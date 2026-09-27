class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n,1);
        vector<int> right(n,1);
        left[0] = nums[0];
        right[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            left[i] *= (nums[i]*left[i-1]);    
        }
        for(int i=n-2;i>=0;i--){
            right[i] *= (nums[i]*right[i+1]);
        }

        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            int l = i==0 ? 1 : left[i-1];
            int r = i==n-1 ? 1 : right[i+1];
            res[i] = l*r;
        }

        return res;
    }
};
