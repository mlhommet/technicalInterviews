//
// Created by Margaux Lhommet on 7/17/16.
//

#ifndef REVISIONS_MAXPRODUCT_H
#define REVISIONS_MAXPRODUCT_H

#include <vector>
#include <iostream>
using namespace std;

int maxProduct(const vector<int> &A) {
    int m = A[0];
    int current_pos=A[0];
    int current_neg = A[0];
    for (int i=1; i<A.size();++i){
        int tp = current_pos;
        current_pos = max(current_neg*A[i], max(current_pos*A[i], A[i]));
        current_neg = min(current_neg*A[i], min(tp*A[i], A[i]));
        m = max(m, max(current_pos, A[i]));
    }
    return m;
}

void testMaxProduct(){
    //int res = maxProduct({2, 3, -2, 4});
    int res = maxProduct({ -3,-2,0,3,3,-3,-3,0,-2,0,-1,0,2,0,1,0,2,0,-1,0,-2,0,-1,0,-3,0,-1,0,2,0,3,0,2,0,2,0,-2,0,1,0,1,0});
    cout<<res<<endl;
}

#endif //REVISIONS_MAXPRODUCT_H
