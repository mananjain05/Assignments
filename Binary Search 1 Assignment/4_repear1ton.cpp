#include<iostream>
using namespace std;
int main(){
    int arr[9]={1,2,3,4,4,5,6,7,8};
    int lo= 0;
    int hi = 9-1;
    
    while(lo<=hi){
        int mid = lo + (hi-lo)/2 ;
        if(arr[mid]!= mid+1 ){
            if( mid==0|| arr[mid-1]==arr[mid]){
                cout<<arr[mid];
                break;
            }
            else if( mid== 8|| arr[mid+1]==arr[mid] ){
                cout<<arr[mid];
                break;
            }
            else{
                hi = mid -1 ;
            }
        }
        else if(arr[mid]==mid+1) {
            lo = mid+1;           
        }                  
    }
    
}

