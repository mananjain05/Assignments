#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if (size == 0)
            return -1;
        else if (index < 0 || index >= size)
            return -1;
        else {
            Node* temp = head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0)
            head = temp;
        if (size > 0) {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);
        if (size == 0)
            head = temp;
        if (size > 0) {
            Node* t = head;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = temp;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        else if (index == 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else {
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        else if (size == 0)
            return;
        else if (index == 0) {
            head = head->next;
        } else if (index == size - 1) {
            Node* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            temp->next = NULL;

        } else {
            Node* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        size--;
    }
    void display (){
        Node *t = head;
        while(t!=NULL){
            cout<<t->val<<" ";
            t= t->next;
        }
    }
};
int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2); // linked list becomes 1->2->3
    int param_1 = obj->get(1); // returns 2
    obj->deleteAtIndex(1); // now the linked list is 1->3
    param_1 = obj->get(1); // returns 3
    obj->display();
    return 0;
}

