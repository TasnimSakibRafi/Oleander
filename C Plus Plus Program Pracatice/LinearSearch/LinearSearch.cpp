# include <iostream>
using namespace std ;
int main (){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key; 
    int result=-1; 
    for (int i=0;i<n;i++){
        if (a[i]==key){
            result =i;
            break;
        }
    }


    if (result != -1){
        cout << "Target found at "<<result;
    }
    else {
        cout << "Target Not Found";
    }
    return 0;




}