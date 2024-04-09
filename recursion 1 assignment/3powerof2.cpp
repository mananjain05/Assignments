#include<iostream>
using namespace std;
bool ispowerof2(int n){
    // if(i> n){
    //     return 0;
    // }
    // else if(i==n){
    //     return 1;
    // }
    // i*=2;
    // return ispowerof2(n,i);
    if(n==1) return 1;
    if(n%2==0){
        return ispowerof2(n/2);
    }
    else {
        return 0;
    }

}
int main(){
    cout<<ispowerof2(65);
}