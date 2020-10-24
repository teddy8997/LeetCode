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
    void deleteNode(ListNode* node) {
    	/*
    	4 -> 5 -> 1 -> 9 假設要移除5

    	我們可以依照下列步驟移除:
    	1)	4 -> 1 -> 1 -> 9	先將要移除點的下一個點的值複製給要移除的點
    	2)	4 -> 1 X-> 1 -> 9	之後再將要移除的點指向下下一個點
    						^
    			 |----------|

    	*/
        node->val = node->next->val;
        node->next = node->next->next;
    }
};