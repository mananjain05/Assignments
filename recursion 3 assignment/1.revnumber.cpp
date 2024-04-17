//Write a recursive function to reverse a number. Avoid preceding 0s in the reversed number.
#include<iostream>
using namespace std;
int reverse(int n, int ans){
    if(n==0) return ans ;
    ans *= 10;
    ans += n%10;
    reverse(n/10,ans);
}
int main(){
    int n;
    cin>>n;
    cout<<reverse(n,0);
}