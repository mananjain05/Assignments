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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int sum = temp1->val + temp2->val;
        ListNode* h = new ListNode(sum % 10);
        ListNode* t = h;
        int c = sum / 10;
        temp1 = temp1->next;
        temp2 = temp2->next;
        ListNode* s;
        
        while (temp1 != NULL && temp2 != NULL) {
            sum = c + temp1->val + temp2->val;
            c = sum / 10;
            s = new ListNode(sum % 10);
            t->next = s;
            t = t->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while (temp1 != NULL) {
            sum = c + temp1->val;
            c = sum / 10;
            s = new ListNode(sum % 10);
            t->next = s;
            t = t->next;
            temp1 = temp1->next;
        }
        
        while (temp2 != NULL) {
            sum = c + temp2->val;
            c = sum / 10;
            s = new ListNode(sum % 10);
            t->next = s;
            t = t->next;
            temp2 = temp2->next;
        }
        
        if (c != 0) {
            s = new ListNode(c);
            t->next = s;
            t = t->next;
        }
        
        return h;
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

    // Example input: l1 = [2, 4, 3], l2 = [5, 6, 4]
    std::vector<int> list1 = {2, 4, 3};
    std::vector<int> list2 = {5, 6, 4};
    
    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);

    std::cout << "List 1: ";
    printLinkedList(l1);
    std::cout << "List 2: ";
    printLinkedList(l2);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    std::cout << "Sum: ";
    printLinkedList(result);

    return 0;
}
