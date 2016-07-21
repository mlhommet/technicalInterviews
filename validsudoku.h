//
// Created by Margaux Lhommet on 7/19/16.
//

#ifndef REVISIONS_VALIDSUDOKU_H
#define REVISIONS_VALIDSUDOKU_H
#include <vector>
#include "utils.h"
#include <iostream>
using namespace std;

int isValidSudoku(const vector<string> &A) {
    // check rows
    for (int i=0; i<A.size(); ++i) {
        vector<int> v(10, 0);
        for (int j = 0; j < A[0].size(); ++j) {
            char c = A[i][j];
            if (isdigit(c)) {
                int d = c - '0';
                v[d]++;
                if (v[d] > 1) return false;
            }
        }
    }

    //check cols
    for (int i=0; i<A[0].size(); ++i){
        vector<int> v(10,0);
        for (int j=0; j<9; ++j){
           char c = A[j][i];
            if (isdigit(c)){
                int d = c - '0';
                v[d]++;
                if (v[d] > 1) return false;
            }
        }
    }

    //check blocks
    for (int b=0; b<9; ++b){
        vector<int> v(10,0);
        for (int i=0; i<A.size()/3; ++i) {
            for (int j = 0; j < A[0].size() / 3; ++j) {
                int p_row = i + (b / 3) * 3;
                int p_col = j + (b % 3) * 3;
                char c = A[p_row][p_col];
                if (isdigit(c)) {
                    int d = c - '0';
                    v[d]++;
                    if (v[d] > 1) return false;
                }
            }
        }
    }
    return true;
}

void testSudoku(){
    vector<string> sudo {"..4...63.", ".........", "5......9.", "...56....", "4.3.....1", "...7.....", "...5.....", ".........", "........." };
    for (auto & it:sudo)
        cout<<it<<endl;
    cout<< isValidSudoku(sudo);
}


#endif //REVISIONS_VALIDSUDOKU_H
