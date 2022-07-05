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
    /**
    算法：两个虚拟头节点指向两个子链表
    维护两个链表small和large，small链表按顺序存储所有小于x的节点，large链表按顺序存储所有大于等于x的节点。遍历完原链表后，我们只要将small链表尾节点指向large链表的头节点即能完成对链表的分隔    
    **/
    ListNode* partition(ListNode* head, int x) {
        // 设small和large节点指向当前链表的末尾节点。
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        // 设smallHead和largeHead分别为两个链表的虚拟头节点，即它们的next指针指向链表的头节点
        // 这样做更便于处理头节点为空的边界条件。
        // 开始时smallHead = small，largeHead = large。
        ListNode* smallHead = small;
        ListNode* largeHead = large;
        // 从前往后遍历链表，判断当前链表的节点值是否小于x
        // 如果小于就将small的next指针指向该节点
        // 否则将large的next指针指向该节点
        while(head != nullptr){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        // 遍历结束后，将large的next指针置空，因为large->next指向原链表的节点可能小于x
        // small->next重新指向largeHead->next，即真正意义上的large链表的头节点
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};