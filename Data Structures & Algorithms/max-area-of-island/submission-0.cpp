class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int cnt = 1;
        int dx[] = {0,-1,0,1};
        int dy[] = {-1,0,1,0};

        int n = grid.size();
        int m = grid[0].size();

        for(int ind=0;ind<4;ind++){
            int x = i+dx[ind];
            int y = j+dy[ind];

            if(x<0 || y<0 || x>=n || y>=m){
                continue;
            }

            if(grid[x][y]==1 && !vis[x][y]){
                cnt += dfs(x,y,grid,vis);
            }

        }

        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int maxCnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(!vis[i][j]){
                        int cnt = dfs(i,j,grid,vis);
                        maxCnt = max(cnt,maxCnt);
                    }
                }
            }
        }

        return maxCnt;
    }
};
