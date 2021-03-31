/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if(lenA < lenB){
            for(int i = 0; i < lenB - lenA; i++){
                headB = headB.next;
            }
        }else{
            for(int i = 0; i < lenA - lenB; i++){
                headA = headA.next;
            }
        }
        while(headA != null && headB != null && headA != headB){
            headA = headA.next;
            headB = headB.next;
        }
        return (headA != null && headB != null)? headA : null;
    }
    private int getLength(ListNode node){
        int count = 0; 
        while(node != null){
            count++;
            node = node.next;
        }
        return count;
    }
}