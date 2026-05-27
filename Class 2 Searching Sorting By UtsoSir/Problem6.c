#include<stdio.h>
#include<stdbool.h>


int binary_search_first_occurrence(int arr[], int n, int target)
{
    int low_idx = 0;
    int high_idx = n-1;
    int first_occurrence = -1;

    while( low_idx <= high_idx )
    {
        int mid_idx = (low_idx + high_idx)/2;
        if( arr[mid_idx] == target)
        {
            first_occurrence = mid_idx;
            high_idx = mid_idx - 1;
        }
        else if( arr[mid_idx] < target)
        {
            low_idx = mid_idx + 1;
        }
        else if( arr[mid_idx] > target)
        {
            high_idx = mid_idx - 1;
        }
    }
    return first_occurrence;
}

int binary_search_last_occurrence(int arr[], int n, int target)
{
    int low_idx = 0;
    int high_idx = n-1;
    int last_occurrence = -1;

    while( low_idx <= high_idx )
    {
        int mid_idx = (low_idx + high_idx)/2;
        if( arr[mid_idx] == target)
        {
            last_occurrence = mid_idx;
            low_idx = mid_idx + 1;
        }
        else if( arr[mid_idx] < target)
        {
            low_idx = mid_idx + 1;
        }
        else if( arr[mid_idx] > target)
        {
            high_idx = mid_idx - 1;
        }
    }
    return last_occurrence;
}

void binary_search_first_last(int arr[], int n, int target)
{
    int first_occur_index = binary_search_first_occurrence(arr, n, target);
    int last_occur_index = binary_search_last_occurrence(arr, n, target);

    printf("First occurrence index of %d is %d\n", target, first_occur_index);
    printf("Last occurrence index of %d is %d\n", target, last_occur_index);
}

int main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i<size; i++)
    {
        printf("Enter %d th element: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter your target: ");
    int target;
    scanf("%d", &target);

    binary_search_first_last(arr, size, target);

}


