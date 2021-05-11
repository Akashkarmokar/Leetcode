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
    vector<int>first,second;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        if(first.size()!=second.size()){
            return false;
        }else{
            for(int i=0;i<first.size();i++){
                if(first[i]!=second[i]){
                    return false;
                }
            }
            return true;
        }
    }
    void dfs1(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            first.push_back(root->val);
        }
        if(root->left){
            dfs1(root->left);
        }
        if(root->right){
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            second.push_back(root->val);
        }
        if(root->left){
            dfs2(root->left);
        }
        if(root->right){
            dfs2(root->right);
        }
    }
};