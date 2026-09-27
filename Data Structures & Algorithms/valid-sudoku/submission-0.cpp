class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> squares(9,0);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                int val = board[i][j]-'1';
                if((rows[i] & (1<<val)) || (cols[j] & (1<<val)) || (squares[(i/3)*3+j/3] & (1<<val))){
                    return false;
                }
                //masking or setting that bit place to 1 or we can say turn on to 1
                rows[i] |= (1<<val);
                cols[j] |= (1<<val);
                squares[(i/3)*3+j/3] |= (1<<val);
            }
        }

        return true;

    }
};
