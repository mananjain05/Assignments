#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        arr[i]=s;
    }
    
    for(int i =0;i<n-1;i++){
        bool flag = true;
        for(int j =0;j<n-i-1;j++){
            
            if(arr[j][0]>arr[j+1][0] ) {
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
        if(flag == true) break;
    }

    
    for(string ele : arr){
        cout<<ele<<endl;
    }
    

}