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
private:
    bool check(TreeNode* root, int minVal, int maxVal){
        
        if(!(minVal < root->val && maxVal>root->val)){
            return false;
        }

        bool leftNode = true;
        bool rightNode = true;
        if(root->left){
            leftNode = check(root->left,minVal,root->val);
        }

        if(root->right){
            rightNode = check(root->right,root->val,maxVal);
        }

        return (leftNode && rightNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        int minVal = INT_MIN;
        int maxVal = INT_MAX;

        return check(root,minVal,maxVal);
    }
};
