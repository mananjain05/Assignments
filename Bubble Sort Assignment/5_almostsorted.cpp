#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int arr[n];
    vector<int> a(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];

    }
    for(int i =0;i<n;i++){
        a[i]=arr[i];
    }
    sort(a.begin(),a.end());
    bool flag = true;
    for(int i = 0;i<n;i++){
        flag = true;
        for(int j =0;j<n;j++){
            
            if(a[i]==arr[j]){
                if(abs(i-j)>1) {
                    flag = false;
                    break;
                }
            }
        }
    }
    cout<<flag;
    

}
// #include <iostream>
// using namespace std;
// int main() {
// int A[5]={7,2,32,5,20};
// int n = 5;
// for (int i = 0; i < n - 1; i++) {
// if (A[i] > A[i + 1]) {
// swap(A[i], A[i + 1]);
// i++;
// }
// }
// int i;
// for (i = 0; i < n - 1; i++)
// if (A[i] > A[i + 1]) {
// cout<<"No"<<endl;
// break;
// }
// if(i == n - 1)cout<<"Yes"<<endl;
// return 0;
// }