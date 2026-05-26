#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int tar;
    cin >> tar;
    int result = -1, left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == tar)
        {
            result = mid;
            break;
        }
        else if (a[mid] < tar)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (result >= 0)
    {
        cout << "Result found at index : " << result;
    }
    else
    {
        cout << " Result not found ";
    }
    return 0;
}
