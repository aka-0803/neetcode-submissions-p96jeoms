class Solution {
private:
    void bfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            for(int adjInd : adj[ind]){
                if(!vis[adjInd]){
                    vis[adjInd] = true;
                    q.push(adjInd);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;

    }
};