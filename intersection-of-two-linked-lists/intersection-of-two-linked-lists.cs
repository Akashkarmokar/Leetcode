
// Explanation Link: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1092898/JS-Python-Java-C%2B%2B-or-Easy-O(1)-Extra-Space-Solution-w-Visual-Explanation

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        
        while(a!=b){
            a = a==null ? headB : a.next;
            b = b==null ? headA : b.next;
        }
        return a;
    }
}