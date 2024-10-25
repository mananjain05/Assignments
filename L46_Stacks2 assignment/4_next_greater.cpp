#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        st.push(nums.size() - 1);
        
        // Traverse in reverse to populate next greater elements
        for(int i = nums.size() - 2; i >= 0; i--) {
            while(st.size() && nums[st.top()] <= nums[i]) st.pop();
            if(st.size()) ans[i] = st.top();
            st.push(i);        
        }
        
        int maxElement = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == -1 && nums[i] != maxElement) {
                for(int j = 0; j < nums.size(); j++) {
                    if(nums[j] > nums[i]) {
                        ans[i] = j;
                        break;
                    }
                }
            }
        }

        // Update ans array with actual values from nums array
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] != -1) ans[i] = nums[ans[i]];
        }
        return ans;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example nums array
    vector<int> nums = {1, 2, 1};
    
    // Calculate next greater elements in circular manner
    vector<int> result = solution.nextGreaterElements(nums);
    
    // Print the result
    cout << "Next greater elements in circular array: ";
    printVector(result);

    return 0;
}
