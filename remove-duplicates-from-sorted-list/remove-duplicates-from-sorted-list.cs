/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode cur = head;
        ListNode pre = null;
        
        HashSet<int> s = new HashSet<int>();
        
        while(cur!=null){
            int val = cur.val;
            if(s.Contains(val)){
                pre.next = cur.next;
                cur = cur.next;
            }else{
                s.Add(val);
                pre = cur;
                cur = cur.next;
            }
        }
        
        return head;
    }
}