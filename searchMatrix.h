//
// Created by Margaux Lhommet on 7/17/16.
//

#ifndef REVISIONS_SEARCHMATRIX_H
#define REVISIONS_SEARCHMATRIX_H

#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    if (A.size() == 0 || A[0].size() == 0) return 0;

    int R = A.size();
    int C = A[0].size();
    int start = 0;
    int end = R * C;

    while (start < end) {
        int med = start + (end - start)/2;
        int med_r = med / C;
        int med_c = med % C;
        if (A[med_r][med_c] == B)
            return 1;
        if (A[med_r][med_c] < B) // search right
            start = med + 1;
        else
            end = med;
    }
    return 0;
}

void testSearchMatrix(){
    vector<vector<int>> A {{22},{31},{36},{44},{49},{90},{91}};
    int res = searchMatrix(A, 36);
    cout<<"Test Search Matrix "<<res<<endl;
}

#endif //REVISIONS_SEARCHMATRIX_H
