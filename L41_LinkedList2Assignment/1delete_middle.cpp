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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next; // Store the node to be deleted
        slow->next = slow->next->next;
        delete temp; // Free the memory of the deleted node
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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.deleteMiddle(head);

    std::cout << "List after deleting middle node: ";
    printList(head);

    // Clean up the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
