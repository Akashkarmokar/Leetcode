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
    public bool IsPalindrome(ListNode head) {
        if(head==null || head.next==null){
            return true;
        }
        
        ListNode head2 = find_mid(head);
        ListNode temp = head;
        while(temp.next!=head2){
            temp = temp.next;
        }
        temp.next = null;
        
        head2 = reverse(head2);
        
        while(head!=null && head2!=null){
            if(head.val != head2.val){
                return false;
            }
            head = head.next;
            head2 = head2.next;
        }
        return true;
        
    }
    
    private ListNode find_mid(ListNode head){
        ListNode a = head;
        ListNode b = head;
        
        while(b!=null && b.next!=null){
            a = a.next;
            b = b.next.next;
        }
        
        return a;
    }
    private ListNode reverse(ListNode head2){
        ListNode cur = head2;
        ListNode next = null;
        ListNode prev = null;
        
        while(cur!=null){
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
}