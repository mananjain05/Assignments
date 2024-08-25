#include <iostream>
#include <vector>
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
    int getDecimalValue(ListNode* head) {
        int ans = 0, i = 0, n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        while (head) {
            ans += (head->val) * (1 << (n - i - 1));
            head = head->next;
            i++;
        }
        return ans;
    }
};

// Helper function to create a linked list from a vector of values
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

    // Example: create a linked list representing the binary number 1011 (11 in decimal)
    vector<int> binaryList = {1, 0, 1, 1};
    ListNode* head = createLinkedList(binaryList);

    int result = solution.getDecimalValue(head);
    cout << "The decimal value is: " << result << endl;

    return 0;
}
