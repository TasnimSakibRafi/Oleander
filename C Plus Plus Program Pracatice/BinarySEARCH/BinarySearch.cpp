#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tar;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> tar;

    int left = 0, right = n - 1, result = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == tar)
        {
            result = mid;
            break;
        }
        else if (a[mid] < left)
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
        cout << "Target Found At :";
        cout << result;
    }
    else
    {
        cout << "Not Found 😊";
    }
    return 0;
}