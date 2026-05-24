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
    TreeNode* buildTreeHelper(int preStart,int preEnd,int inStart, int inEnd, unordered_map<int,int>& inMap, vector<int>& preorder, vector<int>& inorder){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inInd = inMap[root->val];
        int numShift = inInd - inStart;
        root->left = buildTreeHelper(preStart+1,preStart+numShift,inStart,inInd-1,inMap,preorder,inorder);
        root->right = buildTreeHelper(preStart+numShift+1,preEnd,inInd+1,inEnd,inMap,preorder,inorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         unordered_map<int,int> inMap;
         for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
         }

         TreeNode* root = buildTreeHelper(0,preorder.size()-1,0,inorder.size()-1,inMap,preorder,inorder);
         return root;
    }
};
