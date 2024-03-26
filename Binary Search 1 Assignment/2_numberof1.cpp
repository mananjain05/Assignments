#include <iostream>
using namespace std;
int main()
{
    int arr[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};
    int lo = 0;
    int hi = 8;
    int c = 0, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == 1 && arr[mid - 1] == 0)
        {
            c = 1;
            break;
        }
        else if (arr[mid] < 1)
            lo = mid + 1;
        else
        {
            hi = mid - 1;
        }
    }
    if (c == 1)
    {
        c += (8 - mid);
    }
    cout << c;
}