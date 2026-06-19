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
    int helper(TreeNode* root, int& maxDiff){
        if(root==NULL) return 0;
        int left = helper(root->left,maxDiff);
        int right = helper(root->right,maxDiff);

        maxDiff = max(maxDiff,abs(left-right));

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        int maxDiff = 0;
        helper(root,maxDiff);
        return maxDiff>1 ? false : true;
    }
};
