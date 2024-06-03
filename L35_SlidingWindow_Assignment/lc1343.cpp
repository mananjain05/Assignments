#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int count = 0;
        if(sum / k >= threshold) count++;
        int i = 1;
        int j = k;
        while(j < n) {
            sum += arr[j] - arr[i - 1];
            if(sum / k >= threshold) count++;
            j++;
            i++;
        }
        return count;
    }
};

int main() {
    // Sample input
    vector<int> arr = {2, 1, 3, 2, 4, 5, 1, 3, 2};
    int k = 3;
    int threshold = 2;

    // Create Solution object
    Solution sol;
    
    // Get the number of subarrays
    int result = sol.numOfSubarrays(arr, k, threshold);
    
    // Print the result
    cout << "Number of subarrays: " << result << endl;

    return 0;
}
