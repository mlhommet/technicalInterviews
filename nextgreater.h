//
// Created by Margaux Lhommet on 7/19/16.
//

#ifndef REVISIONS_NEXTGREATER_H
#define REVISIONS_NEXTGREATER_H

#include <vector>
#include <stack>
#include "utils.h"
using namespace std;


vector<int> nextGreater(vector<int> &A) {
    stack<int> s;
    vector<int> v (A.size(),-1);
    for (int i=A.size()-1; i>=0; --i){
        int val = A[i];
        while (!s.empty() && s.top()<=val)
            s.pop();
        if (!s.empty()) v[i]=s.top();
        s.push(val);
    }
    return v;
}

void testNextGreater(){
    vector<int> in {39,27,11,4,24,32,32,1};
    vector<int> res = nextGreater(in);
    print_vector(res);
}
#endif //REVISIONS_NEXTGREATER_H
