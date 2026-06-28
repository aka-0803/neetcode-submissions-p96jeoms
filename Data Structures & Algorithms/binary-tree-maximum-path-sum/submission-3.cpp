/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

public:
    // void dfs(TreeNode* root,vector<int>& ans){
    //     if(root==NULL) return;
    //     dfs(root->left,ans);
    //     ans.push_back(root->val);
    //     dfs(root->right,ans);
    // }
    int maxSum = INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL){
            return INT_MIN;
        }

        int left_max = max(0,dfs(root->left));
        int right_max = max(0,dfs(root->right));

        int sum = root->val+left_max+right_max;
        maxSum = max(sum,maxSum);
        return root->val+max(left_max,right_max);
    }
    int maxPathSum(TreeNode* root) {
        // vector<int> ans;
        // dfs(root,ans);
        // int maxSum = INT_MIN;
        // int sum = 0;
        // for(int i=0;i<ans.size();i++){
        //     sum += ans[i];
        //     maxSum = max(sum,maxSum);
        //     if(sum<0){
        //         sum = 0;
        //     }
        // }

        // return maxSum;

        dfs(root);
        return maxSum;

    }
};
