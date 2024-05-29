#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre = vector<int>(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return pre[right];
        return pre[right] - pre[left-1];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5}; // Example input
    NumArray* obj = new NumArray(nums);
    
    // Example queries
    int left = 1, right = 3;
    cout << "Sum of range (" << left << ", " << right << "): " << obj->sumRange(left, right) << endl;
    
    left = 0, right = 4;
    cout << "Sum of range (" << left << ", " << right << "): " << obj->sumRange(left, right) << endl;

    delete obj; // Clean up dynamically allocated memory
    return 0;
}
