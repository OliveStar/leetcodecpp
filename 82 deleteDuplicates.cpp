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
    /*
    *  算法：给定有序链表，重复元素都是连续的，只需要一次遍历，就可以删除所有重复元素
    *  与83题不同，83题重复元素保留1个，本题1个不留
    *  由于链表的头节点可能会被删除，所以需要使用一个虚拟头节点指向链表的头节点
    *  时间复杂度：O(n), 其中n是链表的长度
    *  空间复杂度：O(1)
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy; // cur指向虚拟头节点，开始遍历链表

        // 需要判断cur->next和cur->next->next是否为空
        while(cur->next && cur->next->next){
            // 如果当前节点的值cur->next->val和下一个节点的值cur->next->next->val相同
            // 需要将cur->next以及后面所有拥有相同元素值的链表节点全部删除
            if(cur->next->val == cur->next->next->val){
                int x = cur->next->val;
                // 逐个移除节点，知道cur->next为空或者节点值不再为x
                while(cur->next && cur->next->val == x){
                    cur->next = cur->next->next;
                }
            }
            else{
                // 如果cur->next和cur->next->next的值不相同
                // 说明链表中只有一个cur->next->val，继续遍历下一个节点
                cur = cur->next;
            }
        }
        // 遍历完整个列表，返回虚拟头节点的下一个节点
        return dummy->next;
    }
};