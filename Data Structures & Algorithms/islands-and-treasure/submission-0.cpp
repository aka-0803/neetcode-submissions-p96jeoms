class Solution {
private:
    bool isValid(int i,int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }

        return true;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            auto coord = q.front().first;
            int dist = q.front().second;
            q.pop();
            int x = coord.first;
            int y = coord.second;

            int dx[] = {0,-1,0,1};
            int dy[] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];

                if(isValid(xx,yy,n,m)){
                    if(grid[xx][yy]!=0 && grid[xx][yy]!=-1){
                        if(vis[xx][yy]==0){
                            grid[xx][yy] = dist+1;
                            vis[xx][yy] = 1;
                            q.push({{xx,yy},dist+1});
                        }
                    }
                }
            }

        }
    }
};
