#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        int odd = 0;
        int last_one = -1;
        while (j < n) {
            if (nums[j] % 2 == 1) {
                if (odd < k) {
                    odd++;
                    last_one = j;
                    j++;
                } else {
                    int m = j - last_one;
                    last_one = j;
                    int l = 1;
                    while (nums[i] % 2 == 0) {
                        l++;
                        i++;
                    }
                    count += l * m;
                    i++;
                    j++;
                }
            } else {
                j++;
            }
        }
        if (odd == k) {
            int m = j - last_one;
            int l = 1;
            while (nums[i] % 2 == 0) {
                l++;
                i++;
            }
            count += l * m;
        }

        return count;
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    // Create Solution object
    Solution sol;

    // Get the number of subarrays
    int result = sol.numberOfSubarrays(nums, k);

    // Print the result
    cout << "Number of subarrays: " << result << endl;

    return 0;
}
