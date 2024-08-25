#include <iostream>
#include <algorithm> // For std::max
#include<vector>
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
    ListNode* reverselist(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves and reverse the second half
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        head2 = reverselist(head2);

        // Calculate the maximum twin sum
        int maxSum = 0;
        ListNode* p1 = head;
        ListNode* p2 = head2;
        while (p2) {
            maxSum = max(maxSum, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }

        return maxSum;
    }
};

// Helper function to create a linked list from an array
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

int main() {
    Solution solution;

    // Example: create a linked list with values
    vector<int> listValues = {5, 4, 2, 1}; // Example list
    ListNode* head = createLinkedList(listValues);

    int result = solution.pairSum(head);
    cout << "The maximum twin sum is: " << result << endl;

    return 0;
}
