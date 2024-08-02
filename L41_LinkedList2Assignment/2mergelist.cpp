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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        for (int i = 1; i < a; i++) {
            temp1 = temp1->next;
        }
        ListNode* temp3 = temp1;
        for (int i = a; i <= b + 1; i++) {
            temp3 = temp3->next;
        }
        temp1->next = list2;
        while (temp2->next != nullptr) {
            temp2 = temp2->next;
        }
        temp2->next = temp3;
        if (a != 0) return list1;
        else return list2;
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
    // Create two sample linked lists
    std::vector<int> values1 = {0, 1, 2, 3, 4, 5};
    std::vector<int> values2 = {1000000, 1000001, 1000002};

    ListNode* list1 = createList(values1);
    ListNode* list2 = createList(values2);

    std::cout << "Original list1: ";
    printList(list1);

    std::cout << "Original list2: ";
    printList(list2);

    Solution solution;
    int a = 3, b = 4;
    ListNode* mergedList = solution.mergeInBetween(list1, a, b, list2);

    std::cout << "List after merging: ";
    printList(mergedList);

    // Clean up the allocated memory
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
