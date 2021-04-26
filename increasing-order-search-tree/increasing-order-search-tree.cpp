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
    TreeNode* head = new TreeNode(0);
    TreeNode* ptr = head;
    
    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        head->right = new TreeNode(root->val);
        head = head->right;
        inOrder(root->right);
        return;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        return ptr->right;
    }
};