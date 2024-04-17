//  Given two sorted arrays A and B, generate all possible arrays such that the first element is taken
// from A then from B then from A, and so on in increasing order till the arrays are exhausted. The
// generated arrays should end with an element from B.
// A = {10, 15, 25}
// B = {1, 5, 20, 30}
// Output: {10 20}, {10 20 25 30}, {10 30}, {15 20}, {15 20 25 30}, {15 30},
// {25 30}
#include<iostream>
#include<vector>
using namespace std ;
void generate(int arr[], int brr[] , int sizea , int sizeb , vector<vector<int>>&fans, vector<int> ans,int i , int j){
    if( ans.size()%2 == 0){   
        if(i==sizea) return;
        generate (arr,brr,3,4,fans,ans,i+1,j);
        if(ans.size() == 0 || arr[i]>ans[ans.size()-1]){
            ans.push_back(arr[i]);
            generate (arr,brr,3,4,fans,ans,i+1,j);
        }
        
    }
    else{
        if(j==sizeb) return;
        generate (arr,brr,3,4,fans,ans,i,j+1);
        if(brr[j]>ans[ans.size()-1]) {
            ans.push_back(brr[j]);
            generate (arr,brr,3,4,fans,ans,i,j+1);
        }
        
        if(ans.size()%2==0 && ans.size()!=0 ){
            fans.push_back(ans); 
        }
    }
}

int main(){
    int arr[]={10, 15, 25};
    int brr[]={1, 5, 20, 30};
    vector<vector<int>>fans;
    vector <int> ans;
    generate(arr,brr,3,4,fans,ans,0,0);
    for(vector<int> ele : fans){
        for(int i: ele ){
            cout<<i<< " ";
        }
        cout<<endl;
    }
}