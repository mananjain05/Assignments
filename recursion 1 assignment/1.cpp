#include <iostream>
using namespace std;
int sum (int a, int b){
    if (b == a-1) return 0;
    return  ((b%2)?b:0)+ sum(a,b-1);
}
int main() {
    
    cout<<sum(1,5);
    return 0;
}