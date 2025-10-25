#include<iostream>
using namespace std;
template<typename T>
int seq(T arr[],T var,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==var)
            return i;   
    }
    return -1;
}
template<typename T>

int recseq(T arr[],T var,int n){
    int index=n-1;
    if(arr[index]==var) return index;
    if(index==-1) return -1;
    return recseq(arr,var,n-1);

}
template<typename T>

int binarysearch(T arr[],T var,int n){
    int l=0;
    int r=n-1;
    int mid=(r+l)/2;
    while(l<=r){
        if(arr[mid]>var)r=mid-1; //mid 3 
        else if(arr[mid]<var)l=mid+1;     
        else return mid;

        mid=(r+l)/2;

    }
    return -1;
}
template<typename T>

int recbinarysearch(T arr[],T var,int l,int r){
   int m=(r+l)/2; 
   if(l>r) return -1;
   if(arr[m]==var) return m;
   if(arr[m]>var) return recbinarysearch(arr,var,l,m-1);
   if(arr[m]<var) return recbinarysearch(arr,var,m+1,r);;

}
int main(){
    int arr[]={1,5,6,8,10,12,45,60};
    cout<<(recbinarysearch(arr,60,0,8))<<endl;
    cout<<(binarysearch(arr,60,8))<<endl;
    cout<<(seq(arr,60,8))<<endl;
    cout<<(recseq(arr,60,8))<<endl;

}