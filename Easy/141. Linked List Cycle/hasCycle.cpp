/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
            法一
            使用快慢指針快指針一次走兩步，慢指針一次走一步
            然後檢查快指針有沒有下一個node沒有的話代表他沒有環
            如果有環快慢指針會停留在同一個node
            Time complexity: O(n)
            Space complexity: O(1)
        */
        /*
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast){
            if(!fast->next){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
        */
        /*
            法二使用Hashtable來記錄走過的node
            Time complexity: O(n)
            Space complexity: O(1)
        */
        unordered_set<ListNode*> s;
        while(head){
            if(s.count(head)){
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};