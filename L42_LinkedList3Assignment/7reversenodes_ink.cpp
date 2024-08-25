#include <iostream>
#include <vector>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *agla = head;
        ListNode* end = head;
        ListNode* connector = nullptr;
        
        while (temp) {
            end = temp;
            for (int i = 1; i < k; i++) {
                if (end == nullptr) break;
                end = end->next;
            }
            
            if (end == nullptr) break;
            else agla = end->next;
            if (connector == nullptr) head = end;
            else connector->next = end;
            
            ListNode *curr = temp, *Next = temp;
            ListNode* prev = connector;
            
            while (curr != agla) {
                Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next;
            }
            connector = temp;
            temp->next = agla;
            temp = agla;
        }
        return head;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example: create a linked list with values
    vector<int> listValues = {1, 2, 3, 4, 5}; // Example list
    ListNode* head = createLinkedList(listValues);

    int k = 3; // Number of nodes to reverse in each group
    ListNode* newHead = solution.reverseKGroup(head, k);

    cout << "Reversed list in k-groups: ";
    printLinkedList(newHead);

    return 0;
}
