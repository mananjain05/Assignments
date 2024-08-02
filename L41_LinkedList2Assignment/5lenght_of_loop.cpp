#include<bits/stdc++.h>
using namespace std;
class Node {
public :
    int val ;
    Node * next ;
    Node(int val){
        this->val = val;
        next = NULL ;
    }
};
int main(){
    Node* a = new Node(10) ;
    Node* b = new Node(25) ;
    Node* c = new Node(13) ;
    Node* d = new Node(34) ;
    Node* e = new Node(2) ;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = c;
    Node* slow = a;
    Node* fast = a;
    bool flag = 0;
    while(fast && fast->next){
        
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) {
            flag = 1;
            break;
        }
    }
    if(flag == 0)cout<<0;
    else{
        int count = 1;
    slow = slow->next;
    while(slow != fast) {
        count++;
        slow = slow->next;
    }
    cout<<count<<endl;
    }
    
}