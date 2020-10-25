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
    ListNode* reverseList(ListNode* head) {
        //迴圈
        /*
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
        */
        //遞迴
        if(!head || !head->next){
            return head;
        }
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};