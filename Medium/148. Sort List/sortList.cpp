class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //一直將LIST拆成兩半，直到不能拆，然後再去merge排序合併
        if(!head || !head->next){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        return dummy->next;
    }
};