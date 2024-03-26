#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    int lo = 0;
    int hi = x;
    while(lo<=hi){ 
        long long m = lo + (hi-lo)/2;
        if((x-m*m)==(0)) {
            cout<<1 ;
            return 0;
        
        }
        
        else if ( m*m>x){
            hi=m-1;
        }
        else if(m*m<x){
            lo = m+1;
        }
    }
    cout<<0;
}