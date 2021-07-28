#include<iostream>
using namespace std;

  void merge(int l,int h,int mid,int arr[]){
    int count=0,i=l,j=mid+1;
    int* narr = new int[h+1];
    

    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            narr[count++]=arr[i++];

        }
        else{
            narr[count++]=arr[j++];
        }
        }
        for(;i<=mid;){
            
            narr[count++]=arr[i++];
        }
        for(;j<=h;){
            

            narr[count++]=arr[j++];
        }
        j=l;
        for (int p=0;p<=h-l;p++){
            
            arr[j]=narr[p];
            j++;

        }
        free(narr);

}

void mergesort(int l,int h,int arr[]){
    int mid=(l+h)/2;
    if(l<h){
        mergesort(l,mid,arr);
        mergesort(mid+1,h,arr);
        merge(l,h,mid,arr);
    }

}
void display(int length,int* A){
    for (int i=0;i<=length;i++){
        cout<<A[i]<<" ";
    }
    
}




int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(0,n-1,arr);
    display(n-1,arr);
    return 0;

}
