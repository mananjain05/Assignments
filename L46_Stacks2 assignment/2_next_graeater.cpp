#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> nextLargerNodes(ListNode* head) {
        // Reverse the linked list
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* curr = head;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;

        // Process the reversed list to find next larger nodes
        temp = head;
        stack<int> st;
        st.push(temp->val);
        temp = temp->next;
        vector<int> answer;
        answer.push_back(0);
        while(temp) {
            while(st.size() && st.top() <= temp->val) {
                st.pop();
            }
            if(st.size()) answer.push_back(st.top());
            else answer.push_back(0);

            st.push(temp->val);
            temp = temp->next;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example list: [2, 1, 5]
    vector<int> values = {2, 1, 5};
    ListNode* head = createLinkedList(values);

    // Get the next larger nodes result
    vector<int> result = solution.nextLargerNodes(head);
    
    // Print the result
    cout << "Next larger nodes: ";
    printVector(result);

    return 0;
}
