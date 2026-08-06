#include <iostream>
using namespace std;

int hasIndx(int n,int x){
    return n%x;
}

int main() {
    int n,x;
    cout<<"Enter the key value :"<<endl;
    cin>>n;
    cout<<"Enter the Table Size :"<<endl;
    cin>>x;
    cout<<"Has Index = "<<hasIndx(n,x)<<endl;
    

    return 0;
}

//OUTPUT:
Enter the key value : 25
Enter the Table Size :10
Has index =5
