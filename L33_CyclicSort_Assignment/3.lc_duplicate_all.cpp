#include<bits/stdc++.h>
using namespace std;

void findDuplicates(vector<int>& nums,vector<int>&ans) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int ci = nums[i] - 1;
            if (i == ci) i++;
            else if (nums[ci] == nums[i]) {
                i++;
            } 
            else swap(nums[i], nums[ci]);
        }
        for(int i = 0;i<n;i++){
            if(i+1!= nums[i]) {
                ans.push_back(nums[i]);
            }
        }
}
int main(){
    int arr[]={1,2,2,4,1};
    int n = 5;
    vector<int> nums(arr,arr+n);
    vector<int>ans;
    findDuplicates( nums,ans);
    for(int i = 0 ;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}