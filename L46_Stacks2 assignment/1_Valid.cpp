#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.size() == 0) return false;
                else if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else return false;
            }
        }
        return st.size() == 0;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter the string: ";
    cin >> input;
    if(solution.isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    return 0;
}
