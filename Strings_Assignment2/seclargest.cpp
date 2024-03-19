#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int max =INT_MIN;
    int smax=INT_MIN;
    
    for (int i=0;i<s.size();i++){
        if(s[i]>max) max= s[i];

    }
    for (int i=0;i<s.size();i++){
        if(s[i]>smax && s[i]!=max) smax= s[i];

    }
    cout<<(char)smax;


}