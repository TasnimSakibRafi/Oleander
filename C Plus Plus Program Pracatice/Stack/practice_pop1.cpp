# include <iostream>
using namespace std ;
int maxSize;
int topIdx=-1;
int *stackArr;



bool isFull(){
    return(topIdx==maxSize-1);
}

bool isEmpty (){
    return (topIdx==-1);
}


void push (int data){
    if (!isFull ()){
        stackArr[++topIdx]=data;

    }else {
        cout << "Full";
    }
   
}



int pop(){
    if(!isEmpty()){
        return stackArr[topIdx--];
    }else {
        cout<< "Empty";
        return -1;
    }
    
}

void display(){
    if (isEmpty()){
        cout<<"Empty";
        return;
    }

    cout <<"Element : ";

    for(int i=topIdx;i>=0;i--){
        cout<<stackArr[i]<<" ";

    } 
    cout<< endl;
    }

    int main (){

        int value;
        cin>>maxSize;
        stackArr=new int [maxSize];
        cout<<endl;
        for (int i=0;i<maxSize;i++){
            cin>>value ;
            push(value);
        }
        cout << "Popped :"<< pop()<<endl;
        display(); 

    }