class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto next : adj[node]){
                int next_node = next.first;
                int time = next.second;
                if(time+d<dist[next_node]){
                    dist[next_node] = d+time;
                    pq.push({d+time,next_node});
                }
            }
        }

        int maxTime = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            maxTime = max(dist[i],maxTime);
        }

        return maxTime;
    }
};
