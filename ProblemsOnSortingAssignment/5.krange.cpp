#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int ki =INT_MIN ;
    int km = INT_MAX;
    for(int i =1;i<n;i++){
        if(arr[i-1] >= arr[i]){
            int s =  arr[i-1]+arr[i];
            if((arr[i-1]+arr[i])%2==0) ki = max(ki,s/2);
            else ki = max(ki, s/2 +1);
        }
        else {
            int s =  arr[i-1]+arr[i];
            if((arr[i-1]+arr[i])%2==0) km = min(km,(s/2));
            else km = min(km,s/2);

        }
        
    }
    
    if(km<ki) cout<<-1;
    else cout<< ki <<" "<<km;
}
    
