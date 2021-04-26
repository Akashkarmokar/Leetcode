/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans;
        queue<TreeNode*>q;
        q.push(cloned);
        
        while(!q.empty()){
            TreeNode* u = q.front();
            q.pop();
            ans = u;
            if(u->val == target->val){
                return ans;
            }
            if(u->left!=nullptr){
                if(u->left->val == target->val){
                    ans = u->left;
                    return ans;
                }
                q.push(u->left);
            }
            if(u->right!=nullptr){
                if(u->right->val==target->val){
                    ans = u->right;
                    return u->right;
                }
                q.push(u->right);
            }
        }
        return ans;
    }
};