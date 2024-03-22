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
    vector<int>v(n);
    for(int i =0;i<n;i++){
        v[i]=arr[i];
    }
    sort(v.begin(),v.end());
    for(int i =0;i<n-1;i++){
        bool flag = true;
        for(int j =0;j<n-i-1;j++){
            
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
        if(flag == true) break;
    }
    swap(arr[n-2],arr[n-1]);
    int c =1 , sum = 0;
    for(int i =n-1;i>=0;i--){
        sum += (arr[i]+v[i])*c;
        c*=10;  
    }
    cout<<sum;
    
    
    

}