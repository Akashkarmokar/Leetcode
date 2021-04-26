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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 10005;
        int depth = 0;
        int ansSum = -100005;
        while(!q.empty()){
            int qlen = q.size();
            depth++;
            int sum = 0;
            while(qlen--){
                TreeNode* u = q.front();
                q.pop();
                sum+=u->val;
                if(u->left!=nullptr){
                    q.push(u->left);
                }
                if(u->right!=nullptr){
                    q.push(u->right);
                }
            }
            if(sum>ansSum){
                ansSum = sum;
                level = depth;
            }
        }
        return level;
    }
};