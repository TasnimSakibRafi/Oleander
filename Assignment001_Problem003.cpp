#include <iostream>
using namespace std;

int searchInsert(int arr[], int n, int tar) {
    int low = 0, high = n - 1;
    int pos = n; 

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= tar) {
            pos = mid;      
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }
    return pos;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tar;
    cout << "Enter target: ";
    cin >> tar;

    int pos = searchInsert(arr, n, tar);
    cout << "Insertion index: ";
    cout<< pos;
    cout << endl;

    return 0;
}
