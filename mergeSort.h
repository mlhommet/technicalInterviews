//
// Created by Margaux Lhommet on 6/29/16.
//

#ifndef REVISIONS_MERGESORT_H
#define REVISIONS_MERGESORT_H

#include "utils.h"
#include <iostream>
using namespace std;

class mergeSort {
    static void sort(int arr[], int l, int r){
    if (l<r){
        int m = l+(r-l)/2;
        sort(arr, l, m);
        sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

    static void merge(int arr[], int l, int m, int r){
        // copy the subarrays
        int nL = m-l+1;
        int nR = r-m;
        int L[nL], R[nR];
        for (int i=0; i<nL; ++i)
            L[i] = arr[l+i];
        for (int i=0; i<nR; ++i)
            R[i] = arr[m+i+1];
        // merge the arrays back into arr
        int iL = 0, iR = 0, i = l;
        while (iL<nL && iR<nR)
            arr[i++] = (L[iL]<R[iR]) ? L[iL++] : R[iR++];
        while (iL<nL)
            arr[i++] = L[iL++];
        while (iR<nR)
            arr[i++] = R[iR++];
    }

public:
    void test(){
        int t[] {4,8,3,2,1};
        int size = 5;
        cout<<"Begin tests Merge Sort"<<endl;
        print_array(t,5);
        sort(t,0,5-1);
        print_array(t,5);
    }
};


#endif //REVISIONS_MERGESORT_H
