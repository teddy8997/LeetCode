/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return null;
        }
        int n = 0;
        ListNode cur = head;
        while(cur != null){
            n++;
            cur = cur.next;
        }
        
        k %= n;
        if(k == 0){
            return head;
        }
        
        ListNode fast = head;
        ListNode slow = head;
        for(int i = 0; i < k; i++){
            fast = fast.next;      
        }
        
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        fast.next = head;
        fast = slow.next;
        slow.next = null;
        return fast;
    }
}