#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "+") {
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();
                st.push(two);
                st.push(one);
                st.push(one + two);
            }
            else if(operations[i] == "D") {
                st.push(2 * st.top());
            }
            else if(operations[i] == "C") {
                st.pop();
            }
            else {
                st.push(stoi(operations[i]));
            }
        }
        
        int sum = 0;
        while(st.size()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

// Helper function to print an integer result
void printResult(int result) {
    cout << "Total Score: " << result << endl;
}

int main() {
    Solution solution;
    
    // Example operations array
    vector<string> operations = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    
    // Calculate the total score after operations
    int result = solution.calPoints(operations);
    
    // Print the result
    printResult(result);

    return 0;
}
