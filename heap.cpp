#include<iostream>
#include<vector>
using namespace std;
class heap{
    private:
    int Left(int i){
        return 2*i+1;
    }
    int Right(int i){
        return 2*i+2;
    }
    int Parent(int i){
        return (i-1)/2;
    }
    vector<int>vec;
    public:
    
    void maxHeapify(int index, vector<int>& arr, int n){ // top-down max-Heapify
        int l = Left(index);
        int r = Right(index);
        int largest = index;
        if (l <= (n-1) && arr[l] > arr[index]){
            largest = l;
        }else{
            largest = index;
        }
        if (r <= (n-1) && arr[r] > arr[largest]){
            largest = r;
        }
        
        if (largest != index){
            swap(arr[index], arr[largest]);
            maxHeapify(largest, arr, n);
        }
    }
    void buildMaxHeap(){
        for (int i = (vec.size()/2)-1; i >= 0 ; i--){
            maxHeapify(i, vec, vec.size());
        }
    }
    void insert(int num){ 
        vec.push_back(num);
        int index=vec.size()-1;
        int parent=(index-1)/2;
        // bottom-up max-Heapify
        while(parent>=0 &&vec[parent]<vec[index]){
            swap(vec[index],vec[parent]);
            index=parent;
            parent=(index-1)/2;
        }
        

    }
    int max(){
        return vec[0];
    }
    int min(){
        int parent=(vec.size()-2)/2;
        int minimum=vec[0];
        for (int i =parent;i<vec.size();i++)
            if(vec[i]<minimum)minimum=vec[i];
        return minimum;
    }
    void print(){
        for(int i=0;i<vec.size();i++)
            cout<< vec[i] <<" ";
    }
    void heapSort(){
        for (int i = (vec.size()-1); i > 0; i--){
            swap(vec[0], vec[i]);
            maxHeapify(0, vec, i);
        }
    }
};
int main(){
    heap arr;
    arr.insert(5);
    arr.insert(15);
    arr.insert(50);
    arr.insert(45);
    arr.insert(35);
    arr.insert(25);
    arr.insert(65);

    arr.print();
    arr.heapSort();
    cout << "\n";
    arr.print();
    arr.buildMaxHeap();
    cout << "\n";
    arr.print();

    
}