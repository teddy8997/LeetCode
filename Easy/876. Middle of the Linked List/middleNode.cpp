class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    	//使用快慢指針，快指針走兩步慢指針走一步，快指針走到結尾時慢指針所指的方向就是LINK LIST的中點
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};