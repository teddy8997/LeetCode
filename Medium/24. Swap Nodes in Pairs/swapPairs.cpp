/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        /*
            time complexity: O(n)
            space complexity: O(1)
        */
        //當input只有一個或是沒有節點就直接回傳head
        if(!head || !head->next){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        //終止條件為當你這個head節點不是空的而且還有下一個節點以及下下一個節點
        while(head && head->next && head->next->next){
            ListNode *n1 = head->next;
            ListNode *n2 = n1->next;
            n1->next = n2->next;
            n2->next = n1;
            head->next = n2;
            head = n1;
        }
        return dummy.next;
    }
};