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
    ListNode* removeNodes(ListNode* head) {
        int max = 0;
        stack<ListNode*> s;
        ListNode* newHead = nullptr;
        while(head != nullptr){
            s.push(head);
            head = head->next;
        }

        while(!s.empty()){
            if (s.top()->val >= max){
                max = s.top()->val;
                s.top()->next = newHead;
                newHead = s.top();
            }
            s.pop();
        }

        return newHead;
    }
};