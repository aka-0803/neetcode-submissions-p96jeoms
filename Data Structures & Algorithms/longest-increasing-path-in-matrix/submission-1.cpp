class Solution {
public:
    int helper(int i, int j, int prev, vector<vector<int>>& matrix,vector<vector<int>>& vis,vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || prev>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        vis[i][j] = 1;
        int left = helper(i,j-1, matrix[i][j],matrix,vis,dp); 
        int right = helper(i,j+1, matrix[i][j],matrix,vis,dp);
        int north = helper(i-1,j, matrix[i][j],matrix,vis,dp);
        int south = helper(i+1,j, matrix[i][j],matrix,vis,dp);


        int max1 = max(left,right);
        int max2 = max(north,south);
        vis[i][j] = 0;
        return dp[i][j] = 1 + max(max1,max2);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int maxPath = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                int ans = helper(i,j, -1, matrix,vis,dp);
                maxPath = max(maxPath,ans);
            }
        }
        return maxPath;
    }
};
