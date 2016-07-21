//
// Created by Margaux Lhommet on 7/8/16.
//

#ifndef REVISIONS_SUBSET_H
#define REVISIONS_SUBSET_H

#include <vector>
#include <numeric>
#include "utils.h"

using namespace std;

void genSubsetsIt(int n, int start, vector<int> current, vector<vector<int>> &res){
    if (start == n){
        res.push_back(current);
    }
    else{
        genSubsetsIt(n, start+1, current, res);
        current.push_back(start);
        genSubsetsIt(n, start+1, current, res);
    }
}

vector<vector<int>> generateSubsetsBits(int n){
    int nb = 1 << n; // n moves to the right to get 2^n
    vector<vector<int>> res;
    res.push_back(vector<int>());
    for (int i=0; i<nb;++i){
        vector<int> current;
        for (int j=0; j<n; ++j) {
            if ((1<<j & i) != 0) {
                current.push_back(j);
            }
        }
        res.push_back(current);
    }
    return res;

}

vector<vector<int>> generateSubsets(int n){
    vector<vector<int>> res;
    vector<int> curr;
    //genSubsetsIt(n, 0, curr, res);
//    return res;
    return generateSubsetsBits(n);
}



void testSubsets(int n){
    vector<vector<int>> subs = generateSubsets(n);
    for (int i=0; i<subs.size();++i){
        print_vector(subs[i], false);
    }
}

#endif //REVISIONS_SUBSET_H
