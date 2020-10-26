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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *head = &dummy;
        //l1 l2中的值兩兩比較 直到其中一個元素用完
        while(l1 && l2){
            if(l1->val > l2->val){
                head->next = l2;
                l2 = l2->next;
            }else{
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        //看哪個還沒有用完就直接加到最尾端
        if(l1){
           head->next = l1; 
        }
        if(l2){
            head->next = l2;
        }
        return dummy.next;
    }
};