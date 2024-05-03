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
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
