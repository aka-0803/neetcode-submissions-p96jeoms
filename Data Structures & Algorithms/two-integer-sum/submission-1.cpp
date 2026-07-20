class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> A;
        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(),A.end());
        int l = 0;
        int h = nums.size()-1;

        while(l<=h){
            int val = A[l].first+A[h].first;
            if(target==val){
                return {min(A[l].second,A[h].second),max(A[l].second,A[h].second)};
            }
            else if(target>val){
                l++;
            }else{
                h--;
            }
        }

        return {};
    }
};
