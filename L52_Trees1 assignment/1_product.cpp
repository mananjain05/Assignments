#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left , *right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

int product(Node* root){
    if(root == NULL) return 1;
    return (root->val*product(root->left)*product(root->right));
}
int main(){
    Node * a = new Node(1);
    Node * b = new Node(2);
    Node * c = new Node(3);
    Node * d = new Node(4);
    Node * e = new Node(5);
    Node * f = new Node(6);
    Node * g = new Node(7);
    Node * h = new Node(8);
    Node * i = new Node(9);
    Node * j = new Node(10);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f ;
    c->right = g;
    d->left = h ;
    d->right = i;
    e->left = j;

    cout<<product(a);
}