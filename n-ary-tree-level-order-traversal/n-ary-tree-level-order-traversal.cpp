/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int qlen = q.size();
            vector<int>tmp;
            while(qlen--){
                Node* u = q.front();
                q.pop();
                tmp.push_back(u->val);
                for(int i=0;i<u->children.size();i++){
                    q.push(u->children[i]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};