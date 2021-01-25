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
    public ListNode mergeKLists(ListNode[] lists) {
        return merge(lists, 0, lists.length - 1);
    }
    private ListNode merge(ListNode [] lists, int l, int r){
        if(l > r){
            return null;
        }
        if(l == r){
            return lists[l];
        }
        if(l + 1 == r){
            return mergeTwoLists(lists[l], lists[r]);
        }
        int m = l + (r - l) / 2;
        ListNode l1 = merge(lists, l, m);
        ListNode l2 = merge(lists, m+1, r);
        return mergeTwoLists(l1, l2);
    }
    private ListNode mergeTwoLists(ListNode l1, ListNode  l2){
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(l1 != null && l2 != null){
            if(l1.val > l2.val){
                tail.next = l2;
                l2 = l2.next;
            }else{
                tail.next = l1;
                l1 = l1.next;
            }
            tail = tail.next;
        }
        if(l1 != null){
            tail.next = l1;
        }
        if(l2 != null){
           tail.next = l2; 
        }
        return dummy.next;
    }
}