 #include<bits/stdc++.h>
using namespace std;
int inversion(vector<int>& a, vector<int>& b) {
        int i = 0;
        int j = 0;
        int count = 0;
        while(i<a.size() && j<b.size()){
            if((long long)a[i]>(long long)b[j]*2){
                count += a.size()-i;
                j++;
            }
            else i++;
        }
        return count;
    }
    void merge(vector<int>& a, vector<int>& b, vector<int>& v) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                v[k] = a[i];
                k++;
                i++;
            } else {
                v[k] = b[j];
                k++;
                j++;
            }
        }
        if (i == a.size())
            while (j < b.size())
                v[k++] = b[j++];
        else if (j == b.size())
            while (i < a.size())
                v[k++] = a[i++];
    }
    int mergeSort(vector<int>& v) {
        int count = 0;
        int n = v.size();
        if (n == 1)
            return 0;
        int n1 = n / 2;
        int n2 = n - n / 2;
        vector<int> a(n1), b(n2);

        for (int i = 0; i < n1; i++) {
            a[i] = v[i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = v[n1 + i];
        }
        count += mergeSort(a);
        count += mergeSort(b);
        count += inversion(a, b);
        merge(a, b, v);
        a.clear();
        b.clear();
        return count;
    }

    int main() {
        vector<int>nums{5,1,8,2,3};
        int n = nums.size();
        cout<< mergeSort(nums);
    }