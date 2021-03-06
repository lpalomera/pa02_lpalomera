//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;
class minMaxHeap{
    public:
    //gets minimum element
    void getMin();

    //gets maximum element
    void getMax();

    //inserts element
    void insert(int value);

    //inserts element with no print
    void insert2(int value);


    //deletes maximum element
    void deleteMin();

    //deletes maximum element
    void deleteMax();

    //prints heap from left to right
    void printHeap();

    //swaps the two values located at the indeces
    //void swap(int &ind1, int &ind2);

    //should percolate the new index up if need be
    //void percUP(int i);

    //Helper function to fix a deleted min
    //void TrickleDownMin(int i);

    //Helper function to fix a deleted max
    //void TrickleDownMax(int i);


    private:
    //swaps the two values located at the indeces
    void swap(int &ind1, int &ind2);

    //should percolate the new index up if need be
    void percUP(int i);

    //Helper function to fix a deleted min
    void TrickleDownMin(int i);

    //Helper function to fix a deleted max
    void TrickleDownMax(int i);

    //Helper function that will get max index of possible grand and/or children
    int descendantMax(int i);

    //Will return the max of two values
    int maxCpr(int x, int y);
    
    //Helper function that will get min index of possible grand and/or children
    int descendantMin(int i);

    //Will return the min of two values
    int minCpr(int x, int y);

    //Will return grandparent index
    int GP(int i);

    //Will return parent index
    int PARENT(int i);

    //Given index, will retrieve left child's index
    int LEFT(int i);
    
    //Given index, will retrieve right child's index
    int RIGHT(int i);
    
    //Will correct the min-max heap
    void percolate_down(int value);

    //Vector of values
    std::vector<int> vdata;
};

#endif
