#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int c =0;
    for(int i =0;i<s.size();i++){
        for(int l = 1; l<= s.size()-i;l++){
            string t =s .substr(i,l);
            bool flag = 0;
            for(int j =0;j<t.size();j++){
                if(t[j]!='a' && t[j]!='e'&& t[j]!='i'&& t[j]!='o'&& t[j]!='u') {
                    flag =0;
                    break;
                }

                else flag =1;
            }
            if(flag==1) c++;
        }
        
    }
    cout<<c;

}