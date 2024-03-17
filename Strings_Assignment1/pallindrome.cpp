#include<iostream>
#include<string>
#include<bits\stdc++.h>

using namespace std;
int main(){
    string s;
    getline(cin,s);
    string j = s;

    
    reverse(s.begin(),s.end());
    if (j==s) cout<<1;
    else cout<< -1;
}