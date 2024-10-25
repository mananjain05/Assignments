#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(), 0);
        for(int i = 0; i < prices.size(); i++) {
            ans[i] = prices[i];
        }
        stack<int> st;
        st.push(prices[prices.size() - 1]);
        for(int i = prices.size() - 2; i >= 0; i--) {
            while(st.size() && st.top() > prices[i]) st.pop();
            if(st.size()) ans[i] -= st.top();
            st.push(prices[i]);
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
    
    // Example prices array
    vector<int> prices = {8, 4, 6, 2, 3};
    
    // Calculate final prices after discounts
    vector<int> result = solution.finalPrices(prices);
    
    // Print the result
    cout << "Final prices with discounts: ";
    printVector(result);

    return 0;
}
