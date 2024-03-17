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
    int c=0;
    for(int i =0;i<n;i++){
        if(toupper(str[i])=='A'|| toupper(str[i])=='E'||toupper(str[i])=='I'||toupper(str[i])=='O'|| toupper(str[i])=='U') c++;
    }
    cout<<n-c;
    
}