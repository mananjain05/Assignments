#include <iostream>
#include <stack>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        
        // First pass to filter values in non-decreasing order
        while(temp) {
            while(st.size() && st.top() < temp->val) {
                st.pop();
            }
            st.push(temp->val);
            temp = temp->next;
        }
        
        // Transfer values back to the linked list
        temp = head;
        stack<int> kt;
        while(st.size()) {
            kt.push(st.top());
            st.pop();
        }
        
        while(kt.size()) {
            temp->val = kt.top();
            kt.pop();
            if(kt.size()) temp = temp->next;
            else {
                temp->next = NULL;
                break;
            }
        }
        return head;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& values) {
    if(values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for(int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;
    
    // Create example linked list from vector
    vector<int> values = {5, 2, 13, 3, 8};
    ListNode* head = createList(values);
    
    // Remove nodes and get the modified list
    ListNode* result = solution.removeNodes(head);
    
    // Print the modified list
    cout << "Modified list after removing nodes: ";
    printList(result);

    return 0;
}
