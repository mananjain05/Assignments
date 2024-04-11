#include<iostream>
using namespace std;
void printrev(  int arr[] , int n){
    if(n==-1){
        return ;
    }
    cout<<arr[n]<<" ";
    printrev(arr,n-1);
    
}
int main(){
    int arr[]={1,3,7,5,7};
    printrev( arr ,4);
}
