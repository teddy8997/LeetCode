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
    /*
        Time complexity: O(n)
        Space complexity: O(1)
    */
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //如果fast指針不是nullptr的話代表這個List有奇數個數字，所以斷掉的中點是slow->next
        if(fast){
            slow = slow->next;
        }
        //先將後半段的list反轉
        slow = reverse(slow);
        //和前半段的數一一比較看有無不一樣，如果發現不一樣代表不是回文
        while(slow){
            if(slow->val != head->val){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
private:
    //反轉整個LIST
    ListNode *reverse(ListNode *node){
        ListNode *pre = nullptr;
        ListNode *cur = nullptr;
        while(node){
            cur = node->next;
            node->next = pre;
            pre = node;
            node = cur;
        }
        return pre;
    }
};