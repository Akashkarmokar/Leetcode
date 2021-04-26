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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int qlen = q.size();
            ans++;
            while(qlen--){
                TreeNode* u = q.front();
                q.pop();
                if(u->left==nullptr && u->right==nullptr){
                    return ans;
                }
                if(u->left!=nullptr){
                    q.push(u->left);
                }
                if(u->right!=nullptr){
                    q.push(u->right);
                }
            }
            
        }
        return ans;
    }
};