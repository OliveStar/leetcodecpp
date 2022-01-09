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
    ListNode* findNthFromEnd(ListNode* head, int n){
        ListNode *p1 = head, *p2 = head;
        if(head == nullptr) return head;
        for(int i = 0; i < n; i++){
            p1 = p1->next;
        }
        while(p1 != nullptr){
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = findNthFromEnd(dummy, n+1);
        ListNode *node = p->next;
        p->next = p->next->next;
        delete node;
        return dummy->next;
    }
};