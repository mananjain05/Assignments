#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums,vector<int>&ans) {
        
        int i= 0;
        int n = nums.size();
        while(i<n){
            int ci = nums[i]-1;
            if(i==ci) i++;
            else if(nums[ci]==nums[i]) {
                ans[0]=nums[i];
                i++;
            }
            else swap(nums[i],nums[ci]);
        }
        for(int i = 0;i<n;i++){
            if(i+1!= nums[i]) {
                ans[1]=i+1;
                break;
            }
        }
        return ans;
        
}
int main(){
    int arr[]={1,2,2,4};
    int n = 4;
    vector<int> nums(arr,arr+n);
    vector<int>ans(2);
    findErrorNums( nums,ans);
    for(int i = 0 ;i<2;i++){
        cout<<ans[i];
    }
}