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
    int rec(ListNode* node){
        if (node == NULL) return 0;
        node->val = (node->val * 2) + rec(node->next);
        if (node->val/10 > 0) { node->val = node->val % 10; return 1;}
        else return 0;
    }

    ListNode* doubleIt(ListNode* head) {
        if (rec(head)){
            ListNode * new_head = new ListNode(1, head);
            head = new_head;
        }

        return head;
    }
};