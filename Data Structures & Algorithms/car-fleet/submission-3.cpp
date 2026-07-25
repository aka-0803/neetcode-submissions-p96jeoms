class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> st;
        for(int i=0;i<position.size();i++){
            st.push_back({position[i],speed[i]});
        }

        sort(st.rbegin(),st.rend());

        int fleets = 1;
        double prev = (double)(target-st[0].first)/st[0].second;
        for(int i=1;i<st.size();i++){
            double curr = (double)(target-st[i].first)/st[i].second;
            if(curr>prev){
                fleets++;
                prev = curr;
            }
        }

        return fleets;
        
    }
};
