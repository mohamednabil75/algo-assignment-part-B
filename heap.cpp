#include<iostream>
#include<vector>
using namespace std;
class heap{
    vector<int>vec;
    public:
    void insert(int num){
        vec.push_back(num);
        int index=vec.size()-1;
        int parent=(index-1)/2;
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
};
// int main(){
//     heap arr;
//     arr.insert(5);
//     arr.insert(15);
//     arr.insert(50);
//     arr.insert(45);
//     arr.insert(35);
//     arr.insert(25);
//     arr.insert(65);

//     arr.print();
//     cout<<endl;
//     cout<<arr.min()<<endl;
//     cout<<arr.max()<<endl;

    
// }