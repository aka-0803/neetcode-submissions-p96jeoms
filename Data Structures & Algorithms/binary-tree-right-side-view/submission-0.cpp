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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int cnt = 1;
            while(cnt<=size){
                TreeNode* newNode = q.front();
                q.pop();
                if(cnt==size){
                    res.push_back(newNode->val);
                }
                if(newNode->left){
                    q.push(newNode->left);
                }
                if(newNode->right){
                    q.push(newNode->right);
                }
                cnt++;
            }
        }
        return res;
    }
};
