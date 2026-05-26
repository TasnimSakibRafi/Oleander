#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int array[n]; // variable length array (allowed in GCC/Clang)
    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // Step 1: Find maximum element
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    // Step 2: Count array sized by max+1
    int count[max + 1] = {0};
    int output[n];

    // Step 3: Count occurrences
    for (int i = 0; i < n; i++)
    {
        count[array[i]]++;
    }

    // Step 4: Cumulative count
    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Step 5: Place elements into output
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Step 6: Copy back to original array
    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }

    // Step 7: Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}
