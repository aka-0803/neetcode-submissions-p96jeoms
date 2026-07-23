class Solution {
public:
    bool helper(int i,int j,int ind,string temp,string word,vector<vector<char>>& board){
        
        if(ind==word.size()){
            return true;
        }
        int n = board.size();
        int m = board[0].size();

        if(i>=n || j>=m || i<0 || j<0 || board[i][j]!=word[ind] || board[i][j]=='!'){
            return false;
        }

        temp += word[ind];
        char c = board[i][j];
        board[i][j] = '!';
        bool n_d = helper(i-1,j,ind+1,temp,word,board);
        bool e_d = helper(i,j+1,ind+1,temp,word,board);
        bool s_d = helper(i+1,j,ind+1,temp,word,board);
        bool w_d = helper(i,j-1,ind+1,temp,word,board);

        board[i][j] = c;
        return (n_d || e_d || s_d || w_d);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    string temp = "";
                    if(helper(i,j,0,temp,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
        //return helper(0,"",word,board);
    }
};
