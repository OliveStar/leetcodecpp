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
    // 用mLeft表示第m个节点的前一个节点，用mPosi表示第m个节点
    // 因为在反转链表指定部分之后需要修改相应的节点，因此需要用它们缓存两个节点
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        ListNode *cur = head, *pre = NULL;
        ListNode *mLeft = NULL, *mPosi = NULL;
        int cnt = 1;
        while(cnt < left){
            pre = cur;
            cur = cur->next;
            cnt++;
        }
        mLeft = pre;
        mPosi = cur;
        while(cnt <= right){
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
            cnt++;
        }
        if(mLeft) mLeft->next = pre;
        else head = pre;
        mPosi->next = cur;
        return head;
    }
};