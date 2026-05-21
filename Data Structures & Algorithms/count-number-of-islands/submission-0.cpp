class Solution {
private:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        int n =grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;
        int dx[] = {0,-1,0,1};
        int dy[] = {-1,0,1,0};
        while(!q.empty()){
            auto temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            for(int ind=0;ind<4;ind++){
                int xx = x + dx[ind];
                int yy = y + dy[ind];
                if(isValid(xx,yy,n,m) && grid[xx][yy]=='1' && vis[xx][yy]!=true){
                    q.push({xx,yy});
                    vis[xx][yy] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        //count the number of islands
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]!=true){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
