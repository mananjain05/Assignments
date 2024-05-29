#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pre(n+1, 0);
        for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }

        vector<int> post(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            post[i] = post[i+1] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            if(pre[i] == post[i+1]) return i;
        }
        
        return -1;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution sol;
    int result = sol.pivotIndex(nums);

    // Output the result
    cout << "Pivot index: " << result << endl;

    return 0;
}
