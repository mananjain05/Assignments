#include<iostream>
#include<string>
#include<bits\stdc++.h>
#include<vector>
using namespace std;
int main(){
    
    string str;
    getline(cin,str);
    int n = str.size();
    
    reverse(str.begin()+(n/2),str.end());
    cout<< str;

}