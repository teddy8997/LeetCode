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
/* 
    把節點分成兩群一種是小於x的;另一種是大於x的
    最後再把這兩段接起來
    time complexity: O(n)
    space complexit: O(1)
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode before_head(0);
        ListNode* before = &before_head;
        ListNode after_head(0);
        ListNode* after = &after_head;
        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = after_head.next;
        return before_head.next;
    }
};