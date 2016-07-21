//
// Created by Margaux Lhommet on 7/4/16.
//

#ifndef REVISIONS_KTHSMALLER_H
#define REVISIONS_KTHSMALLER_H

#include <vector>
#include <iostream>
using namespace std;

class kthsmaller {

    // Insert val in heap A
    static void insert(vector<int> &A, int val){

    }

    static void maxHeapify(vector<int> & A, int n){
        int l=n*2+1;
        int r=n*2+2;
        int larger = n;
        if (l<A.size() && A[larger]<A[l]) larger = l;
        if (r<A.size() && A[larger]<A[r]) larger = r;
        if (larger != n){
            int tmp = A[larger];
            A[larger] = A[n];
            A[n] = tmp;
            maxHeapify(A, larger);
        }
    }

public:
    static int getKth(const vector<int> & A, int k){
        vector<int> heap (A.begin(), A.begin()+k);
        //heapify the heap
        for (int i=heap.size()/2; i>=0; --i){
            maxHeapify(heap, i);
        }
        //insert the other elements
        for (int i=heap.size(); i<A.size();++i){
            if (A[i]<heap[0]){
                heap[0]=A[i];
                maxHeapify(heap,0);
            }
        }
        //return the max = the top of the heap;
        return heap[0];
    }

    static void test(vector<int> v={1,4,6,0,3,9,7,8,2,15}, int k=5){
        cout<<"Test K-th smallest element"<<endl<<"Input:"<<endl;
        print_vector(v, false);
        cout<<k<<"th element is: "<< getKth(v,k)<<endl;
        sort(v.begin(),v.end());
        cout<< "true result is " << v[k-1]<<endl;
    }


};


#endif //REVISIONS_KTHSMALLER_H
