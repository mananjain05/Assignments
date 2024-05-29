#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        ans[0] = 2 * nums[0];
        int max = nums[0];
        for(int i = 1; i < n; i++) {
            if(max < nums[i]) max = nums[i];
            ans[i] = ans[i-1] + max + nums[i];
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4, 5};

    Solution sol;
    vector<long long> result = sol.findPrefixScore(nums);

    // Output the result
    cout << "Prefix scores: ";
    for(long long score : result) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
