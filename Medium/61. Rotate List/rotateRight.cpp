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
    ListNode* rotateRight(ListNode* head, int k) {
        //如果你的LIST是空的就回傳NULL
        if(!head){
            return NULL;
        }
        //計算LIST中的個數
        ListNode *cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }

        k = k % n; // 處理k > LIST元素個數的這種情況

        //利用快慢指針讓快指針先走K步
        ListNode *fast = head;
        ListNode *slow = head;
        for(int i = 0; i < k; i++){
              fast = fast->next;
        }
        //再讓快指針和慢指針一起走，慢指針會指向要中斷的節點
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        //將快指針指向頭
        fast->next = head;
        //將快指針移到新的頭
        fast = slow->next;
        //慢指針指向NULL
        slow->next = NULL;
        return fast;
    }
};