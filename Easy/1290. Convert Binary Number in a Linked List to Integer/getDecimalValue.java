/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        String s = "";
        while(true){
            s += Integer.toString(head.val); 
            head = head.next;
            if(head == null){
                break;
            }
        }
        return Integer.valueOf(s,2); //轉10進位
    }
}