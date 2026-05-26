#include <iostream>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i=0;i<n;i++){
        cin >>A[i];
    }

    // selection Sort
    int min ;
    for (int i=0;i<n-1;i++){
        min =i;
        for (int j=i+1;j<n;j++){
            if (A[j]<A[min]){
                min = j;
            }
        }
        if (min != i){
            swap(A[i],A[min]);
        }

    }

    for (int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }

    return 0;
}