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
 #include <stack>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 快慢指针+栈，O(N)空间复杂度和O(N)时间复杂度，比单纯用栈节省一半的空间
        if(head == nullptr) return false;
        stack<int> list;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p1 = head;
        ListNode *p2 = slow;
        while(p2!=nullptr){
            list.push(p2->val);
            p2=p2->next;
        }
        while(!list.empty()){
            int n = list.top();
            if(p1->val != n) return false;
            list.pop();
            p1 = p1->next;
        }
        return true;
        //快慢指针+反转链表，O(1)空间复杂度，O(N)时间复杂度，有bug未调试
        /*
        ListNode *pa=head;
        ListNode *trav=slow;
        ListNode *trav1=slow->next;
        ListNode *tmp = trav;
        while(trav != nullptr && trav1 != nullptr){
            trav = trav1;
            trav->next = tmp;
            trav1 = trav1->next;
            tmp = trav;
        }
        slow->next = nullptr;
        ListNode *pb = trav;
        while(pa != nullptr && pb != nullptr){
            if(pa->val != pb->val)
                return false;
        }
        return true;
        */
    }
};