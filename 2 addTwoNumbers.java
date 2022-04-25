/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    // 递归法
    /*
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = l1.val + l2.val; // 每一位的和
        int carry = sum / 10; // 进位
        ListNode res = new ListNode(sum % 10);
        if(l1.next != null || l2.next != null || carry != 0){
            l1 = l1.next != null ? l1.next : new ListNode(0);
            l2 = l2.next != null ? l2.next : new ListNode(0);
            l1.val += carry;
            res.next = addTwoNumbers(l1, l2);
        }
        return res;
    }
    */
    // 迭代法
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0; // 每一位的和
        int carry = 0; // 进位
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        while(l1 != null && l2 != null){
            sum = l1.val + l2.val + carry;
            cur.next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1.next;
            l2 = l2.next;
            cur = cur.next;
        }

        while(l1 != null){
            sum = l1.val + carry;
            cur.next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1.next;
            cur = cur.next;
        }

        while(l2 != null){
            sum = l2.val + carry;
            cur.next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2.next;
            cur = cur.next;
        }

        if(carry != 0){
            cur.next = new ListNode(carry);
        }

        return dummy.next;
    }
}