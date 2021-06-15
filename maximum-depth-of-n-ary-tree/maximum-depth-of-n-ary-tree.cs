/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution {
    public int MaxDepth(Node root) {
        if(root==null){
            return 0;
        }
        else{
            int ans = 0;
            
            Queue<Node> q = new Queue<Node>();
            q.Enqueue(root);
            
            while(q.Count!=0)
            {
                ans++;
                int len = q.Count;
                for(int i=0;i<len;i++){
                    Node u = q.Peek();
                    q.Dequeue();
                    for(int j=0;j<u.children.Count;j++)
                    {
                        q.Enqueue(u.children[j]);
                    }
                }
            }
            
            return ans;
        }
    }
}