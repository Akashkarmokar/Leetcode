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
    // int ans = 0;
    void dfs(TreeNode* root,int curNum,int& ans){  // preOrder Travarse
        if(root== nullptr){
            return ;
        }
        curNum = (curNum<<1) | root->val;
        if(root->left == nullptr && root->right == nullptr){
            ans+=curNum;
        }
        dfs(root->left,curNum,ans);
        dfs(root->right,curNum,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0, curNum = 0;
        dfs(root,curNum,ans);
        return ans;
    }
};