#include <iostream>
#include<vector>
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        if(head == NULL || head->next == NULL) return head;

        ListNode *odd = head, *even = head->next;
        ListNode *eh = even;

        head = head->next;
        if(head->next == NULL) return temp;
        else head = head->next;

        int i = 0;
        while(head) {
            if(i == 0) {
                odd->next = head;
                odd = odd->next;
                i = 1;
            } else {
                even->next = head;
                even = even->next;
                i = 0;
            }
            head = head->next;
        }

        odd->next = eh;
        even->next = NULL;
        return temp;
    }
};

// Helper function to create a linked list from an array
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
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example input: [1, 2, 3, 4, 5]
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    std::cout << "Original List: ";
    printLinkedList(head);

    ListNode* newHead = solution.oddEvenList(head);

    std::cout << "Odd-Even List: ";
    printLinkedList(newHead);

    return 0;
}
