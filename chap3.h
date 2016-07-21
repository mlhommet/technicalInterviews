//
// Created by Margaux Lhommet on 7/6/16.
//

#ifndef REVISIONS_CHAP3_H
#define REVISIONS_CHAP3_H

#include <vector>
#include "utils.h"
using namespace std;

// In a 2-D matrix, every row is increasingly sorted from left to right, and the last number in each row is not greater
// than the first number of the next row.
bool findMatrix(const vector<vector<int>> & m, int v){
    if (m.empty()) return false;
    int rows = m.size();
    int cols = m[0].size();
    int left = 0;
    int right = rows*cols-1;
    while (left<=right){
        int mid = left + (right-left)/2;
        int r = mid / cols;
        int c = mid % cols;
        int val = m[r][c];
        if (val == v)
            return true;
        if (val<v)
            left = mid+1;
        else
            right = mid-1;
    }
    return false;
}

void testMatrix(){
    vector<vector<int>> m = { {1,3,4}, {5,8,12}, {15,16,17}};
    print_matrix(m);
    int n = 17;
    string s = (findMatrix(m, n))? "True":"False";
    cout<<"searching for "<< n<< " = "<< s<<endl;
}



#endif //REVISIONS_CHAP3_H
