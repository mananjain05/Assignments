#include<iostream>
#include<stack>
using namespace std;
int main(){
     stack<int> st;
     int k = 2;
     st.push(4);
     st.push(3);
     st.push(2);
     st.push(1);
     stack<int> temp;
     for(int i = 1;i<k ;i++){
        temp.push(st.top());
        st.pop();
     }
     st.pop();
     while(temp.size()){
        st.push(temp.top());
        temp.pop();
     }
}