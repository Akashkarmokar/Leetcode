/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool IsCousins(TreeNode root, int x, int y) {
        int[] d = new int[105];
        int[] p = new int[105];
        
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        
        d[root.val] = 0;
        p[root.val] = -1;
        
        while(q.Count!=0)
        {
            TreeNode u = q.Peek();
            q.Dequeue();
            
            TreeNode left = u.left;
            TreeNode right = u.right;
            
            if(left!=null){
                q.Enqueue(left);
                d[left.val] = d[u.val]+1;
                p[left.val] = u.val;
            }
            
            if(right!=null){
                q.Enqueue(right);
                d[right.val] =d[u.val]+1;
                p[right.val] = u.val;
            }
        }
        if(d[x]==d[y] && p[x]!=p[y]){
            return true;
        }
        else{
            return false;
        }
    }
}