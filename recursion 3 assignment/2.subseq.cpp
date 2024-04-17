// Print all the increasing sequences of length k from first n natural numbers.
#include<iostream>
#include<vector>
using namespace std;
void subs(int k , int n ,vector<int>ans,int i ){
    if(i==n+1){
        if(ans.size()==k){
            for(int ele : ans){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if((n-i+1+ans.size())<k) return;
    subs(k,n,ans,i+1);
    ans.push_back(i);
    subs(k,n,ans,i+1);
    
}
int main(){
    int k,n;
    cin>>k>>n;
    vector<int>ans;
    subs(k,n,ans,1);
}