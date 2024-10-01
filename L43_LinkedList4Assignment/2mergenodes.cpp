#include <iostream>
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* h = new ListNode(10);
        ListNode* t = h;
        int sum = 0;
        head = head->next; // skip the initial 0 node
        while(head){
            if(head->val == 0){
                ListNode* s = new ListNode(sum);
                sum = 0;
                t->next = s;
                t = t->next;
            }
            else{
                sum += head->val;
            }
            head = head->next;
        }
        return h->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if(size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Sample input where we expect to merge between 0s
    int arr[] = {0, 3, 1, 0, 4, 5, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create linked list from array
    ListNode* head = createList(arr, size);
    
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    ListNode* result = sol.mergeNodes(head);
    
    cout << "Merged Nodes List: ";
    printList(result);

    return 0;
}
