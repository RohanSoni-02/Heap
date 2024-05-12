//
//  main.cpp
//  Heaps
//
//  Created by Rohan Soni on 3/5/2024.
//

#include <iostream>
#include <vector>
using namespace std;

class Heap{
private:
    vector<int> heap;
    
    int leftChild(int index){
        return 2*index + 1;
    }
    
    int rightChild(int index){
        return 2*index + 2;
    }
    
    int parent(int index){
        return (index - 1)/2;
    }
    
    void swap(int index1, int index2){
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }
public:
    void insert(int value){
        heap.push_back(value);
        int current = int(heap.size()) - 1;
        while (current > 0 && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }
    
    void printHeap(){
        cout<<"\n [";
        for (size_t i=0; i<heap.size(); i++) {
            cout<<heap[i];
            if (i < heap.size()-1) {
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }
    
    int remove(){
        if (heap.empty()) {
            return INT_MIN;
        }
        int maxValue = heap.front();
        if (heap.size()==1) {
            heap.pop_back();
        }
        else{
            heap[0]= heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return maxValue;
    }
    
    void sinkDown(int index){
        int maxIndex = index;
        while (true) {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);
            if (leftIndex<heap.size() && heap[leftIndex] > heap[maxIndex]) {
                maxIndex = leftIndex;
            }
            if (rightIndex<heap.size() && heap[rightIndex] > heap[maxIndex]) {
                maxIndex = rightIndex;
            }
            if (maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            }
            else{
                return;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Heap* myheap = new Heap();
    myheap->insert(40);
    myheap->insert(38);
    myheap->insert(39);
    myheap->insert(41);
    myheap->insert(100);
    myheap->insert(103);
    
    myheap->printHeap();
    
    myheap->remove();
    myheap->printHeap();
    
    myheap->remove();
    myheap->printHeap();
}
