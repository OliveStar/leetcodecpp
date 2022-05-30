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
 * 
 算法：递归的终止条件是链表中没有节点，或者链表中只有一个节点，此时无法进行交换。
如果链表中至少有两个节点，则在两两交换链表中的节点之后，原始链表的头节点变成新的链表的第二个节点，原始链表的第二个节点变成新的链表的头节点。链表中的其余节点的两两交换可以递归地实现。在对链表中的其余节点递归地两两交换之后，更新节点之间的指针关系，即可完成整个链表的两两交换。
 */
 /*
 复杂度分析
时间复杂度：O(n)，其中n是链表的节点数量。需要对每个节点进行更新指针的操作。
空间复杂度：O(n)，其中n是链表的节点数量。空间复杂度主要取决于递归调用的栈空间。
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 用 head 表示原始链表的头节点，新的链表的第二个节点
        if(head == nullptr || head->next == nullptr)
            return head;
        // 用 newHead 表示新的链表的头节点，原始链表的第二个节点
        ListNode* newHead = head->next;
        // 令 head.next = swapPairs(newHead.next)
        // 表示将其余节点进行两两交换，交换后的新的头节点为 head 的下一个节点
        head->next = swapPairs(newHead->next);
        // 原始链表中的其余节点的头节点是 newHead.next
        // 令newHead.next = head，即完成了所有节点的交换
        newHead->next = head;
        // 最后返回新的链表的头节点 newHead
        return newHead;
    }
};