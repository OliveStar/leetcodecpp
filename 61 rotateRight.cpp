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
    /**
        算法：采用快慢指针的方法，先让fast指针遍历k个节点，然后同时移动fast和slow指针
        fast遍历到链表尾时slow即是新的链表头，这样把链表尾节点的next指针指向原链表头就完成链表的右移
        k > n时循环右移
     */
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* newHead = NULL;
        int cnt = 0;
        while(fast && cnt < k){
            fast = fast->next;
            cnt++;
        }
        if(!fast){
            k %= cnt;
            cnt = 0;
            fast = head;
            while(fast && cnt < k){
                fast = fast->next;
                cnt++;
            }
        }
        while(fast){
            if(!fast->next){
                ListNode* tmp = slow;
                fast->next = head;
                newHead = slow->next;
                tmp->next = NULL;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return newHead;
    }
};