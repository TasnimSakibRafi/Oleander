#include<stdio.h>
#include<stdbool.h>

bool binary_search(int arr[], int n, int target)
{
    int low_idx = 0;
    int high_idx = n-1;

    while( low_idx <= high_idx )
    {
        int mid_idx = (low_idx + high_idx)/2;
        if( arr[mid_idx] == target)
        {
            return true;
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
    return false;
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

    bool found = binary_search(arr, size, target);

    if(found == true)
    {
        printf("%d is found\n", target);
    }
    else
    {
        printf("%d is not found\n", target);
    }
}
