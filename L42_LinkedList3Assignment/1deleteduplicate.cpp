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
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* lo = dummy;
        ListNode* hi = head;

        while (hi != nullptr) {
            // Check if hi has duplicates
            if (hi->next != nullptr && hi->val == hi->next->val) {
                // Skip all nodes with the same value
                while (hi->next != nullptr && hi->val == hi->next->val) {
                    hi = hi->next;
                }
                // Connect lo to the node after the duplicates
                lo->next = hi->next;
            } else {
                // No duplicates, move lo forward
                lo = lo->next;
            }
            // Move hi forward
            hi = hi->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const std::vector<int>& vals) {
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
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function to test the Solution
int main() {
    Solution solution;

    // Example 1: 1->2->3->3->4->4->5 should return 1->2->5
    std::vector<int> vals1 = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head1 = createLinkedList(vals1);
    std::cout << "Original list: ";
    printLinkedList(head1);

    ListNode* result1 = solution.deleteDuplicates(head1);
    std::cout << "List after removing duplicates: ";
    printLinkedList(result1);

    // Example 2: 1->1->1->2->3 should return 2->3
    std::vector<int> vals2 = {1, 1, 1, 2, 3};
    ListNode* head2 = createLinkedList(vals2);
    std::cout << "Original list: ";
    printLinkedList(head2);

    ListNode* result2 = solution.deleteDuplicates(head2);
    std::cout << "List after removing duplicates: ";
    printLinkedList(result2);

    return 0;
}
