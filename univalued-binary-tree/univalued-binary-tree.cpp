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
    void dfs(TreeNode* root,set<int>& ans){
        if(root == nullptr){
            return ;
        }
        dfs(root->left,ans);
        dfs(root->right,ans);
        ans.insert(root->val);
        
    }
    bool isUnivalTree(TreeNode* root) {
        if(root->left==nullptr && root->right == nullptr){
            return true;
        }
        set<int> s;
        dfs(root,s);
        return s.size()==1?true:false;
    }
};