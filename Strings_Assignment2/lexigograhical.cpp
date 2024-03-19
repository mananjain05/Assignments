#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "i am at pw";
    string w="";
    string maxw= "";
    int n = s.size();
    for(int i =0;i<n;i++){
        if(s[i]==' '){
            maxw=max(maxw,w);
            w = "";

        }
        else{
            w += s[i];
        }
    }
    maxw=max(maxw,w);
    cout<<maxw<<endl;
}