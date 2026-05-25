class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt = 0;
        //max end
        int preEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            if(start<preEnd){
                cnt++;
                preEnd = min(preEnd,intervals[i][1]);
            }else{
                preEnd = intervals[i][1];
            }
        }

        return cnt;
    }
};
