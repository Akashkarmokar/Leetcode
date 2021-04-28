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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*>ans;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back(root);
        while(!q.empty()){
            int qlen = q.size();
            ans.clear();
            while(qlen--){
                TreeNode* u = q.front();
                q.pop();
                if(u->left!=NULL){
                    q.push(u->left);
                    ans.push_back(u->left);
                }
                if(u->right!=NULL){
                    q.push(u->right);
                    ans.push_back(u->right);
                }
            }
        }
        TreeNode* va = *ans.begin();
        return va->val;
    }
};