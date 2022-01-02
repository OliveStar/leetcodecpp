#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

// solution
// 本题没有虚拟头节点，head就是第一个节点
ListNode* deleteNode(ListNode* head, int val) {
        //头节点特殊处理
        if(head == NULL) return head;
        else if(head->val == val){
            head = head->next;
            return head;
        }
        //双指针删节点
        ListNode* prev = head;
        ListNode* cp = head->next;
        while(cp){
            if(cp->val == val){
                prev->next = cp->next;
                return head;
            }
            prev=cp;
            cp=cp->next;
        }
        return head;
    }

// display
void printlist(ListNode* head){
    cout << "[";
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]";
    return;
}

int main() {
    int val;
	cin >> val;
	
    int n;
    cin >> n;
    ListNode*head;
    if(n == -1) {
        head = NULL;
    }
    else{
        head = new ListNode(n);
        cin.get();
	    ListNode* cp = head;
	    ListNode* newNode;
	    //创建链表
	    while(cin >> n){
	        newNode = new ListNode(n);
	        cp->next=newNode;
	        cp=cp->next;
	        cin.get();//读取单个字符,过滤掉逗号/空格/分号等英文分隔符
	    }
    }
	head=deleteNode(head,val);
	printlist(head);
	return 0;
}