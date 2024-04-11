 #include<iostream>
 #include<vector>
using namespace std;
int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector <int> newnums(n-1);
        for(int i = 0 ; i<n-1 ; i++){
            newnums[i]=(nums[i] + nums[i+1]) % 10 ;
        }
        return triangularSum(newnums) ;
}
int main(){
    vector<int>nums = {1,2,3,4,5};

    cout<<triangularSum(nums);
}