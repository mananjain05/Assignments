#include <iostream>
#include <vector>

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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        // Remove leading nodes with the target value
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // If the list becomes empty
        if (head == nullptr) return nullptr;

        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array of values
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    std::vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createList(values);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    int val = 6;
    head = solution.removeElements(head, val);

    std::cout << "List after removing elements with value " << val << ": ";
    printList(head);

    // Clean up the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
