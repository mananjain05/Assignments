#include<iostream>
using namespace std;
int main(){
    int a[]={1,3,5,8,4};
    int n = 5;
    int idx1 = -1 , idx2=-1;
    for(int i = 0;i<n-1;i++){
        if(a[i]>a[i+1]){
            if(idx1==-1){
                idx1 = i;
                idx2 = i+1;
            }
            else idx2= i+1;
        }
    }
    swap(a[idx1],a[idx2]);
    for(int ele : a) cout<<ele<<" ";
}