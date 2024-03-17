#include<iostream>
#include<string>

using namespace std;
int main(){
    int n;
    cin>>n;
    char str[n+1];
    for(int i =0;i<n;i++){
        char s;
        cin>>s;
        str[i]=s;
    }
    for(int i =0;i<n;i++){
        if(i%2!=0) str[i]='#';
    }
    for(int i =0;i<n;i++){
        cout<<str[i];
    }
}