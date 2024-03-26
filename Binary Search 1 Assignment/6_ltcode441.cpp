#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
        int lo = 0;
        int hi = n;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if( n == (mid*(mid+1))/2  ){
                cout<<mid;
                return 0 ;
            } 
            else if (n>mid*(mid+1)/2  )  lo = mid+1;
            else {
                hi = mid -1;
            }
        }
        cout<< hi;
}