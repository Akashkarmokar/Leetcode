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
    void dfs(TreeNode* root,int low,int high,long long& sum){
        long long val = root->val;
        if(val>=low && val<=high){
            sum+=val;
        }
        if(root->left){
            dfs(root->left,low,high,sum);
        }
        if(root->right){
            dfs(root->right,low,high,sum);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        long long sum = 0;
        dfs(root,low,high,sum);
        return sum;
    }
};