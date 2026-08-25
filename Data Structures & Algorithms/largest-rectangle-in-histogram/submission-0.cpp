class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n  = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int nse = i;
                int curr = st.top();
                st.pop();
                int prev = st.empty() ? -1 : st.top();
                int area = heights[curr] * (nse-prev-1);
                maxArea = max(maxArea,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int curr = st.top();
            st.pop();
            int prev = st.empty() ? -1 : st.top();
            int area = heights[curr] * (nse-prev-1);
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};
