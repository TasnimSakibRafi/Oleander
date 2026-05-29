#include<stdio.h>


void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i]; /// key / first element of the unsorted portion of array
                          /// which we will insert in the correct position of sorted portion

        int j = i-1; /// index of the element from where we started comparing

        /// move elements of the sorted portion that are greater than the key,
        /// one position ahead of their current position

        while( j >= 0 && arr[j] > key) /// j = -1 --> arr[-1+1] = key
                                       /// j = 0 and arr[0] = 5 < 6(key)--> arr[0+1] = key;
        {
            arr[j+1] = arr[j]; /// move element one position ahead

            j = j - 1;  /// go to the next element with which we compare
        }
        arr[j+1] = key; ///place the key in its correct position(empty space after the element smaller than the key)
    }
}

void print_array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    //int arr[5] = {12,11, 13, 5, 6};

    printf("Enter size of the array: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting: ");
    print_array(arr, n);

    insertion_sort(arr, n);

    printf("After Sorting: ");
    print_array(arr, n);

    float median;
    if (n %2 == 1)
    {
        /// total number of element is odd
        median = arr[n/2];
    }else
    {
        ///total number of element is even
        median = (arr[(n-1)/2] + arr[n/2])/2.0;
    }
    printf("Median of the array: %f\n", median);

}

