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
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == nullptr) return head;

        ListNode *temp = head;
        ListNode *Next = temp->next;
        temp->next = nullptr;
        ListNode* head2 = temp;
        temp = Next;

        while(temp) {
            Next = temp->next;
            ListNode* temp2 = head2;
            ListNode* prev = nullptr;

            while(temp2) {
                if(temp2->val >= temp->val) {
                    if(prev == nullptr) {
                        temp->next = temp2;
                        head2 = temp;
                    } else {
                        prev->next = temp;
                        temp->next = temp2;
                    }
                    temp = Next;
                    break;
                } else {
                    prev = temp2;
                    temp2 = temp2->next;
                }
            }

            if(temp != Next) {
                prev->next = temp;
                temp->next = nullptr;
                temp = Next; 
            }
        }
        return head2;
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

    // Example input: [4, 2, 1, 3]
    std::vector<int> values = {4, 2, 1, 3};
    ListNode* head = createLinkedList(values);

    std::cout << "Original List: ";
    printLinkedList(head);

    ListNode* sortedHead = solution.insertionSortList(head);

    std::cout << "Sorted List: ";
    printLinkedList(sortedHead);

    return 0;
}
