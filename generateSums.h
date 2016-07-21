//
// Created by Margaux Lhommet on 7/19/16.
//

#ifndef REVISIONS_GENERATESUMS_H
#define REVISIONS_GENERATESUMS_H

#include <vector>
#include "utils.h"

using namespace std;


void generateSums(vector<int> & candidates, int target, vector<vector<int>> &res, vector<int> current, int pos){
    if (target==0)
        res.push_back(current);
    else if (pos<candidates.size()){
        for (int i=pos; i<candidates.size();++i){
            if (candidates[i]<=target){
                current.push_back(candidates[i]);
                generateSums(candidates, target-candidates[i], res,current,i);
                current.pop_back();
            }
            else break;
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end() );
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vector<int>> res;
    vector<int> v;
    print_vector(A);
    generateSums(A, B, res, v,0);
    return res;
}

void testCombinationSum(){
    vector<int> A {2,2,3};
    vector<vector<int>> res = combinationSum(A, 7);
    print_matrix(res);
}

#endif //REVISIONS_GENERATESUMS_H
