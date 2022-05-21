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
    // 难点在于分组之间的衔接以及最后一个分组的处理
    // 考虑以下五种情况：
    // 空链表、节点个数小于k的链表、节点个数等于k的链表、节点个数大于k且最后一个分组节点数小于k的链表、节点个数大于k且最后一个分组节点数等于k的链表
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head; // 记录当前节点
        ListNode* prev = NULL; // 记录前一个节点
        ListNode* cTail = head; // 记录当前分组倒序后的最后一个节点（即该分组的第一个节点）
        ListNode* pTail = NULL; // 记录前一个分组倒序后的最后一个节点
        int cnt = 0;

        head = NULL;
        while(curr){
            // 通过pTail和cTail完成分组间的衔接
            if(cnt == k){
                if(!head) head = prev;
                if(pTail) pTail->next = prev;
                prev = NULL;
                pTail = cTail;
                cTail = curr;
                cnt = 0;
            }
            ListNode * temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
            cnt++;
        }
        // 最后一个分组如果不够k个节点，再将它倒序一次以恢复原来的顺序。
        if(cnt != k){
            curr = prev;
            prev = NULL;
            while(curr){
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = prev;
                prev = temp;
            }
        }
        else
            cTail->next = NULL;
        if(!head) head = prev;
        if(pTail) pTail->next = prev;

        return head;
    }
};