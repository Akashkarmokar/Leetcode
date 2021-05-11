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
    int mx = 0;
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        dfs(root,0);
        return mx+1;
    }
    void dfs(TreeNode* root,int depth){
        if(root->left){
            dfs(root->left,depth+1);
            mx = max(mx,depth+1);
        }
        if(root->right){
            dfs(root->right,depth+1);
            mx = max(mx,depth+1);
        }
    }
};