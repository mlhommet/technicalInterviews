//
// Created by Margaux Lhommet on 6/29/16.
//

#ifndef REVISIONS_QUICKSORT_H
#define REVISIONS_QUICKSORT_H


class Quicksort {

public:
    static void sort(int arr[], int l, int r){
        if (l<r){
            int p = partition(arr, l, r);
            sort(arr, l, p-1);
            sort(arr, p+1, r);
        }
    }

    static void swap(int *a, int *b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }

    static int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low;
        for (int j=low; j<high; ++j){
            if (arr[j]<=pivot){
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i+1], &arr[high]);
        return i+1;
    }


public:
    void test(){
        int t[] {4,8,3,2,1};
        int size = 5;
        cout<<"Begin tests Quick Sort"<<endl;
        print_array(t,5);
        sort(t,0,5-1);
        print_array(t,5);
    }
};


#endif //REVISIONS_QUICKSORT_H
