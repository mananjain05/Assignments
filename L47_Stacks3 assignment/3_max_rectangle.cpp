#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int ans = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> h(cols, 0);

        for (int i = 0; i < rows; i++) {
            // Update heights array based on row values
            for (int j = 0; j < cols; j++) {
                h[j] = (matrix[i][j] == '0') ? 0 : h[j] + 1;
            }

            // Next Smaller to the Right (NSR)
            vector<int> nsi(cols, cols);
            stack<int> st;
            for (int j = cols - 1; j >= 0; j--) {
                while (!st.empty() && h[j] <= h[st.top()]) st.pop();
                if (!st.empty()) nsi[j] = st.top();
                st.push(j);
            }

            // Previous Smaller to the Left (PSL)
            vector<int> psi(cols, -1);
            stack<int> kt;
            for (int j = 0; j < cols; j++) {
                while (!kt.empty() && h[j] <= h[kt.top()]) kt.pop();
                if (!kt.empty()) psi[j] = kt.top();
                kt.push(j);
            }

            // Calculate maximum rectangle area for the current row
            for (int j = 0; j < cols; j++) {
                ans = max(ans, (nsi[j] - psi[j] - 1) * h[j]);
            }
        }
        return ans;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (char val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    // Example input matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    // Display the input matrix
    cout << "Input Matrix:" << endl;
    printMatrix(matrix);

    // Calculate and print the maximal rectangle area
    int result = solution.maximalRectangle(matrix);
    cout << "Maximum Rectangle Area: " << result << endl;

    return 0;
}
