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
    利用兩個pointer一個指向奇數節點,一個指向偶數節點
    把偶數節點cur後面的那個奇數節點提前到pre後面
    然後pre cur各往前走一步此時cur又指向偶數節點pre指向奇數節點的尾端
    做到直到所有的偶數節點都提前即可
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur && cur->next){
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};