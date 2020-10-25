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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            利用快慢指針讓快指針快慢指針n步
            那麼當快指針到尾端時慢指針就會停在要刪除節點的前一個節點
            所以只要將前一個節點指向下下一個節點就好
        */
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        for(int i = 1; i <= n+1; i++){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
        
    }
};