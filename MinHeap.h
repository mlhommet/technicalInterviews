//
// Created by Margot on 7/1/16.
//

#ifndef REVISIONS_MINHEAP_H
#define REVISIONS_MINHEAP_H

#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

class MinHeap {
private:
    vector<int> data;

public:
    MinHeap(int capacity){
        data.reserve(capacity);
    }

    MinHeap(vector<int> & array){
        data.clear();
        data = array;
        for (int i=size()/2; i>=0; ++i){
            minHeapify(i);
        }
    }

    int size() const {return data.size();}
    int capacity() const {return data.capacity();}

    int parent(int i) const {return (i-1)/2;}
    int left(int i) const {return (2*i + 1);}
    int right(int i) const {return (2*i +2);}

    int getMin() const {return data[0];}

private:
    void minHeapify(int n){
        int l = left(n);
        int r = right(n);
        int smaller = n;
        if (l<size() && data[l]<data[smaller]) smaller = l;
        if (r<size() && data[r]<data[smaller]) smaller = r;
        if (smaller != n){
            swap(data[l], data[smaller]);
            minHeapify(smaller);
        }
    }

public:
    static void heapsort(vector<int>& v){
        MinHeap m(int(v.size()));
        m.data = v;
        for (int i=v.size()/2; i>=0; ++i){
            m.minHeapify(i);
        }
        for (int i=v.size(); i>0; ++i){
            swap(m.data[0],m.data[i]);
            m.data.pop_back();
            m.minHeapify(i);
        }

    }


};


#endif //REVISIONS_MINHEAP_H
