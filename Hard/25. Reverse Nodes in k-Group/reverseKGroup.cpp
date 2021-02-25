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
    參考:https://github.com/labuladong/fucking-algorithm/blob/master/%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E7%B3%BB%E5%88%97/k%E4%B8%AA%E4%B8%80%E7%BB%84%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.md
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        ListNode *a = head;
        ListNode *b = head;
        for(int i = 0; i < k; i++){
            if(!b){
                return head;
            }
            b = b->next;
        }
        ListNode *newHead = reverse(a, b); //[a,b)
        a->next = reverseKGroup(b, k);
        return newHead;
    }
private:
    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode *pre = NULL;
        ListNode *cur = a;
        while(cur != b){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};