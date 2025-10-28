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
    vector<pair<int,int>> pq;
    public:
    
    void maxHeapify(int index, vector<int>& arr, int n){ // top-down max-Heapify
        int l = Left(index);
        int r = Right(index);
        int largest = index;
        if (l <= (n-1) && arr[l] > arr[index])
            largest = l;
        if (r <= (n-1) && arr[r] > arr[largest])
            largest = r;
        
        if (largest != index){
            swap(arr[index], arr[largest]);
            maxHeapify(largest, arr, n);
        }
    }

    void maxHeapify(int index, vector<pair<int,int>>& arr, int n){
        int l = Left(index);
        int r = Right(index);
        int largest = index;
        if (l <= (n-1) && arr[l].first > arr[index].first) 
            largest = l;
        if (r <= (n-1) && arr[r].first > arr[largest].first) 
            largest = r;

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

    void insertWithPriority(int value, int priority){
        pq.push_back({priority, value});
        int index = pq.size() - 1;
        int parent = (index - 1)/2;

        while(parent >= 0 && pq[parent].first < pq[index].first){
            swap(pq[parent], pq[index]);
            index = parent;
            parent = (index - 1)/2;
        }
    }

    pair<int,int> extractMaxPriority(){
        if (pq.empty()) return {-1,-1};
        pair<int,int> maxElem = pq[0];
        pq[0] = pq.back();
        pq.pop_back();
        if (!pq.empty()) maxHeapify(0, pq, pq.size());
        return maxElem;
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

/*int main(){
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
    
}*/

int main(){
    heap h;

    h.insertWithPriority(10, 2);
    h.insertWithPriority(18, 0);
    h.insertWithPriority(20, 5);
    h.insertWithPriority(15, 3);

    cout << "\nextracting in priority order:\n";
    while (true){
        auto top = h.extractMaxPriority();
        if (top.first == -1) break;
        cout << "Value: " << top.second << endl;
    }
}