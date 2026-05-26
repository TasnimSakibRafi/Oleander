#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n]; 
    cout << "Enter Sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    cin >> target;








    int left = 0, right = n - 1;
    int result = -1;  // default if not found







    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            result = mid;
            break;  // target found
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // search right half
        }
        else {
            right = mid - 1; // search left half
        }
    }








    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found (-1)" << endl;

    return 0;
}
