#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        long long sum = 0, len = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            sum += nums[j];
            len++;
            if(sum * len < k) {
                j++;
            } else {
                while(sum * len >= k) {
                    sum -= nums[i];
                    ans += j - i;
                    len--;
                    i++;
                }
                j++;
            }
        }
        while(i < n) {
            ans += j - i;
            i++;
        }
        return ans; 
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 2, 3, 4, 5};
    long long k = 10;

    // Create Solution object
    Solution sol;

    // Get the number of subarrays
    long long result = sol.countSubarrays(nums, k);

    // Print the result
    cout << "Number of subarrays: " << result << endl;

    return 0;
}
