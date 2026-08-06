#include<iostream>
using namespace std;

void merge(int A[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int B[100];
    while(i<=mid && j<=ub){
        if(A[i] <= A[j]){
            B[k]=A[i];
            i++;
        }
        else{
            B[k]=A[j];
            j++;
        }
        k++;
    }
    while(j<=ub){
        B[k]=A[j];
        j++;
        k++;
    }
     while(i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }
    for(k=lb;k<=ub;k++){
        A[k]=B[k];
       
    }
    }


void mergeSort(int A[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(A,lb,mid);
        mergeSort(A,mid+1,ub);

        merge(A,lb,mid,ub);
    }

}


int main(){
    
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;

    int A[n];
    cout<<"Enter Elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    mergeSort(A,0,n-1);

    cout<<"Sorted Array"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}
