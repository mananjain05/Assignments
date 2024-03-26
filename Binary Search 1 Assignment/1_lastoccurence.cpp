#include <iostream>
using namespace std;
int main()
{
    int arr[9] = {-1, 3, 6, 9, 9, 14, 16, 20, 21};
    int lo = 0;
    int hi = 9;
    int x;
    cin >> x;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x && arr[mid + 1] != x)
        {
            cout << mid;
            break;
        }
        else if (arr[mid] < x)
            lo = mid + 1;
        else if (arr[mid] > x)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
}