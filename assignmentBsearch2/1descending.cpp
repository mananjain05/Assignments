#include<iostream>
using namespace std;
int main(){
    int arr[]={9,6,3,1};
    int n;
    cin>>n;
    int hi = 3;
    int lo = 0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==n) {
            cout<<mid;
            break;
        }
        else if(arr[mid]>n){
            lo = mid+1;

        }
        else hi = mid-1;
    }


}