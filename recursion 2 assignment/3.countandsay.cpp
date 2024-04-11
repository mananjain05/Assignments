#include<iostream>
using namespace std;
string countAndSay(int n) {
        if (n == 1)
            return ("1");
        if (n == 2)
            return ("11");
        string s = countAndSay(n - 1);
        string ans = "";
        int i = 0;
        char ch = s[i];
        int c = 1;
        i++;
        while (i < s.size()) {

            if (s[i] == ch) {
                c++;
                i++;
            } else {
                ans += char(48 + c);
                ans += ch;
                c = 1;
                ch = s[i];
                i++;
                if (i >= s.size())
                    break;
            }
        }
        ans += char(48 + c);
        ans += ch;

        return ans;
    }
int main(){
    cout<<countAndSay(3);
}