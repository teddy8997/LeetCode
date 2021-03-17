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
/*
    主要策略就是把node中的值都先存到array然後再去交換array的值後再把值存回listnode中
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        List<Integer> l = new ArrayList<>();
        ListNode h = head;
        while(h != null){
            l.add(h.val);
            h = h.next;
        }
        int tmp = l.get(k - 1); 
        l.set(k-1, l.get(l.size() - k));
        l.set(l.size() - k, tmp);

        int i = 0;
        ListNode h2 = head;
        while(h2 != null){
            h2.val = l.get(i);
            h2 = h2.next;
            i++;
        }
        return head;
    }
}