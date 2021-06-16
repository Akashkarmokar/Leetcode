/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        HashSet<ListNode> s = new HashSet<ListNode>();
        
        bool ok = false;
        while(head!=null){
            if(s.Contains(head)){
                ok = true;
                break;
            }
            s.Add(head);
            head = head.next;
        }
        
        return ok;
    }
}