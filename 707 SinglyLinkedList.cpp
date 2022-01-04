#include <iostream>

using namespace std;

// solution
struct Node
{
    int val;
    struct Node *next;
    Node() : val(0),next(nullptr) {}
    Node(int v) : val(v),next(nullptr) {}
    Node(int v, struct Node *x) : val(v), next(x) {}
};

class MyLinkedList {
    struct Node *head;
    int size;
public:
    MyLinkedList() {
        head = new Node();
        size = 0;
    }
    
    int get(int index) {
        if(index <0 || index >= size) return -1;
        struct Node *cur = head;
        while(index >= 0){
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        struct Node *newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        struct Node *cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        struct Node *newNode = new Node(val);
        cur->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        else if(index == size){
            addAtTail(val);
        }else if(index <= 0){
            addAtHead(val);
        }else{
            struct Node *front = head->next;
            struct Node *back = head;
            while(index > 0){
                front = front->next;
                back = back->next;
                index--;
            }
            struct Node *newNode = new Node(val,front);
            back->next = newNode;
            size++;
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index <0 || index >= size || size == 0) return;
        struct Node *trav = head;
        struct Node *del = nullptr;
        for(int i=0; i < index; i++)
            trav = trav->next;
        del = trav->next;
        trav->next = del->next;
        delete del;
        size--;
    }
    
    void printList(){
        struct Node *cur = head;
        if(cur->next == nullptr) cout << "None" << endl;
        cur = cur->next;
        while(cur != nullptr){
            cout << cur->val << "->";
            cur = cur->next;
        }
        cout << endl;
        cout << "链表长度：" << size << endl;
    }
};

int main() {
    MyLinkedList* linkedList = new MyLinkedList();
    //linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(2,1);
    linkedList->printList();
    linkedList->addAtIndex(1,4);
    linkedList->addAtIndex(0,5);
    linkedList->addAtIndex(2,6);
    linkedList->printList();
    linkedList->addAtIndex(-5,6);
    linkedList->printList();
    linkedList->deleteAtIndex(3);
    linkedList->printList();
    linkedList->deleteAtIndex(3);
    linkedList->printList();
    linkedList->deleteAtIndex(2);
    linkedList->printList();
    linkedList->deleteAtIndex(0);
    linkedList->printList();
    linkedList->deleteAtIndex(0);
    linkedList->printList();
    linkedList->deleteAtIndex(0);
    linkedList->printList();
	return 0;
}