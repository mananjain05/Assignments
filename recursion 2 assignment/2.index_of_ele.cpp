#include<iostream>
using namespace std;
int find(  int arr[] , int n , int k){
    if(n==-1){
        return -1;
    }
    if(arr[n]== k) return n;
    find(arr,n-1 , k);
    
}
int main(){
    int arr[]={1,3,7,5,7};
    cout<<find( arr ,4,1);
}
