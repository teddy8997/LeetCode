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
    先計算LIST長度後再利用這個長度去做RAND()就完成了
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
        ListNode* cur = head;
        count = 0;
        while(cur != nullptr){
            cur = cur->next;
            count++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % count;
        ListNode* cur = head_;
        while(n-- > 0){
            cur = cur->next;
        }
        return cur->val;
    }
private:
    int count;
    ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */