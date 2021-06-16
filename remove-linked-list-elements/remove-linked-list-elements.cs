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
    public ListNode RemoveElements(ListNode head, int val) {
        if(head==null){
            return head;
        }
        while(head!=null && head.val == val){
            head = head.next;
        }
        ListNode cur = head;
        ListNode pre = null;
        
        while(cur!=null){
            if(cur.val==val){
                pre.next = cur.next;
                cur = cur.next;
            }else{
                pre = cur;
                cur = cur.next;
            }
        }
        
        return head;
    }
}