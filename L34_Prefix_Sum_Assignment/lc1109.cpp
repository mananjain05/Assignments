#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n, 0);
        int m = bookings.size();
        for(int i = 0; i < m; i++) {
            answer[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] <= n - 1) answer[bookings[i][1]] -= bookings[i][2];
        }
        for(int i = 1; i < n; i++) {
            answer[i] += answer[i - 1];
        }
        return answer;
    }
};

int main() {
    // Example input
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;

    Solution sol;
    vector<int> result = sol.corpFlightBookings(bookings, n);

    // Output the result
    cout << "Resulting seats booked: ";
    for(int seats : result) {
        cout << seats << " ";
    }
    cout << endl;

    return 0;
}
