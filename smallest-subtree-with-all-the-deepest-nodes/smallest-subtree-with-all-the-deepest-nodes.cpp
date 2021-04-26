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
    
    pair<int,TreeNode*> deep_go(TreeNode* root){
        
        if(root==NULL){
            return {0,NULL};
        }
        
        pair<int,TreeNode*> left_go = deep_go(root->left);
        pair<int,TreeNode*> right_go = deep_go(root->right);
        
        int left_depth = left_go.first;
        int right_depth = right_go.first;
        
        if(left_depth == right_depth){
            return {left_depth+1,root};
        }else if(left_depth>right_depth){
            return {left_depth+1,left_go.second};
        }else{
            return {right_depth+1,right_go.second};
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deep_go(root).second;
    }
};