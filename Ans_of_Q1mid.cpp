#include <iostream>
using namespace std;





int main() {
    int n, searchMark;
    cout << "Enter number of students: ";
    cin >> n;

    int *marks = new int[n];
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
        cin >> marks[i];


    
 
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (marks[j] > marks[maxIndex])
                maxIndex = j;
        }
     
        int temp = marks[i];
        marks[i] = marks[maxIndex];
        marks[maxIndex] = temp;
    }

    cout << "Enter mark to search: ";
    cin >> searchMark;

   
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (marks[mid] == searchMark) {
            result = mid;    
            low = mid + 1;    
        } else if (marks[mid] < searchMark)
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << "Sorted marks: [";
    for (int i = 0; i < n; i++) {
        cout << marks[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]";
    cout<< endl;

    if (result != -1)
        cout << "Last occurrence of " << searchMark << " is at index = " << result << endl;
    else {
        cout << "Mark not found!";
         cout << endl;
    }
    delete[] marks;
    return 0;
}
