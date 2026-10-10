class Solution {
public:
    bool helper(int row, int target, vector<vector<int>>& matrix){
        int n = matrix[0].size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(matrix[row][mid]>target){
                r=mid-1;
            }else if(matrix[row][mid]<target){
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            bool rowCheck = helper(mid,target,matrix);
            if(rowCheck){
                return true;
            }else if(target<matrix[mid][n-1]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};
