class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r = k-1;
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        l++;
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<l){
                pq.pop();
            }
            l++;
            res.push_back(pq.top().first);
        }
        return res;
    }
};
