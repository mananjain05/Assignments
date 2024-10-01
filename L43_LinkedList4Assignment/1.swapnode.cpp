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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head, *end = NULL, *Next = head;
        while(temp && temp->next){   
            Next = Next->next->next;
            if(end){
                end->next = temp->next;
            }
            else head = temp->next;
            
            temp->next->next = temp;
            temp->next = Next;
            end = temp;
            temp = Next;
        }
        return head;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list
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
    // Sample input
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Create linked list from array
    ListNode* head = createList(arr, size);
    
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    ListNode* result = sol.swapPairs(head);
    
    cout << "Swapped List: ";
    printList(result);

    return 0;
}
