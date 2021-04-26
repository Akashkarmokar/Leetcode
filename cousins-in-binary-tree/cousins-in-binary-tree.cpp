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
    bool isCousins(TreeNode* root, int x, int y) {
        // map<int,int>d,p;
        int d[105],p[105];
        queue<TreeNode*>q;
        q.push(root);
        
        d[root->val]=0;
        p[root->val]=-1;
        
        while(!q.empty()){
            TreeNode* u = q.front();
            q.pop();
            
            TreeNode* left = u->left;
            TreeNode* right = u->right;
            
            if(left!=nullptr){
                q.push(left);
                d[left->val] = d[u->val] + 1;
                p[left->val] = u->val;
            }
            if(right!=nullptr){
                q.push(right);
                d[right->val] = d[u->val] + 1;
                p[right->val] = u->val;
            }
        }
        if(d[x]==d[y] && p[x]!=p[y]){
            return true;
        }else{
            return false;
        }
    }
};