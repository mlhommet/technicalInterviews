//
// Created by Margaux Lhommet on 7/2/16.
//

#ifndef REVISIONS_HEAPSORT_H
#define REVISIONS_HEAPSORT_H

#include <vector>
#include "utils.h"
using namespace std;

class heapsort {
public:
    static void sort(vector<int> & array){
        int heap_size = array.size();
        // build a heap
        for (int i=heap_size/2-1; i>=0; --i){
            heapify(array, i, heap_size);
        }
        for (int i=heap_size; i>0; --i) {
            swap(array[i], array[heap_size]); // put the first element of the heap to the end
            heap_size--;
            heapify(array, i, heap_size);
        }
    }

    static void heapify(vector<int> & array, int i, int n){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int max = i;
        if (l<n && array[l]<array[max]) max = l;
        if (r<n && array[r]<array[max]) max = r;
        if (max != i){
            swap(array[i], array[max]);
            heapify(array, max, n);
        }
    }

    static void test(){
        cout<<"Test heap sort"<<endl;
        vector<int> a {5,13,2,25,7,17,20,8,4};
        print_vector(a);
        sort(a);
        print_vector(a);
        cout<<"End tests heapsort"<<endl;
    }

};


#endif //REVISIONS_HEAPSORT_H
