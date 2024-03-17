#include<iostream>
#include<string>
#include<bits\stdc++.h>
#include<vector>
using namespace std;
int main(){
    
    string str;
    getline(cin,str);
    int n = str.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans*=10;
        ans+=str[i]-48;        
    }
    cout<< ans;

}