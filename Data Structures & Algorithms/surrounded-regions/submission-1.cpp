class Solution {
public:
    int n,m;
    void dfs(int i, int j, vector<vector<char>>& board){
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        board[i][j] = 'T';

        for(int ind=0;ind<4;ind++){
            int x = i + dx[ind];
            int y = j + dy[ind];

            if(x<0 || y<0 || x>=n || y>=m){
                continue;
            }

            if(board[x][y]=='O'){
                dfs(x,y,board);
            }
        }
    }

    

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board);
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                } else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }   
    }
};
