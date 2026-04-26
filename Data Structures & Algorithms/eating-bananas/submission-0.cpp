class Solution {
private:
    int solve(int k, vector<int>& piles){
        int hours = 0;
        for(auto x: piles){
            hours += ceil((double)x/k);
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int low = 1;
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(solve(mid,piles)<=h){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;

    }
};
