#include<iostream>
using namespace std;
int main(){
    int arr[][4]={{0,0,1,1},{0,1,1,1},{1,1,1,1}};
    int ans =0;
    for(int i = 0; i < 3;i++){
        int lo= 0;
        int hi = 3;
        int c =0 , mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2 ;    
            if(arr[i][mid]==1  && (arr[i][mid-1]==0|| mid==0)) {
                c = 1;
                break;    
            } 
            else if (arr[i][mid]<1) lo = mid + 1;
            else {
                hi = mid - 1 ;
            }       
        }
        if(c==1){
            c += (3-mid);
        }
        if(c>ans){
            ans = c;
            cout<<i<<endl;;
        }
    
    }
    
    cout<<ans;
}