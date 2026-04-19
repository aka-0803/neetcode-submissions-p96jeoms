class Solution {
private:
    void solve(int i, int j, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[i][j] = true;

        int dx[] = {0,-1,0,1};
        int dy[] = {-1, 0, 1, 0};

        for(int ind=0;ind<4;ind++){
            int x = i+dx[ind];
            int y = j + dy[ind];

            if(x<0 || y<0 || x==heights.size() || y==heights[0].size() || ocean[x][y]==true || heights[x][y]<heights[i][j]){
                continue;
            }

            solve(x,y,ocean,heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> alt(n,vector<bool>(m,false));

        for(int i=0;i<m;i++){
            solve(0,i,pac,heights);
            solve(n-1,i,alt,heights);
        }

        for(int i=0;i<n;i++){
            solve(i,0,pac,heights);
            solve(i,m-1,alt,heights);
        }

        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && alt[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
