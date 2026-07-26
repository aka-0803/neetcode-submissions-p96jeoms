class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> pos(n,0);
        pos[n-1] = n-1;
        st.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--){
             while(!st.empty() && temperatures[i]>=st.top().first){
                st.pop();
             }
             int index = i;
             if(!st.empty()){
                index = st.top().second;
             }
             pos[i] = index;
             st.push({temperatures[i],i});
        }

        for(int i=0;i<n;i++){
            pos[i] = pos[i]-i;
        }

        return pos;
    }
};
