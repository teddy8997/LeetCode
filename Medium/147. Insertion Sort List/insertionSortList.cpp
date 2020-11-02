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
    ListNode* insertionSortList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy; //pre 和 pre->next之前是要插入的內容
        ListNode *cur = head; //指向要插入到前面的元素
        ListNode *next = nullptr; //儲存cur的下一個節點
        while(cur){
            next = cur->next;
            while(pre->next && pre->next->val < cur->val){
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            pre = dummy;
            cur = next;
        }
        return dummy->next;
    }
};