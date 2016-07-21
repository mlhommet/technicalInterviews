//
// Created by Margot on 7/13/16.
//

#ifndef REVISIONS_STITCH_H
#define REVISIONS_STITCH_H

#include <vector>
#include <math.h>
#include <iostream>
#include "utils.h"

using namespace std;
    string stitch_s(string &a, string &b, int overlap){
        // create the string with a's size + complement from b.
        string s = a + b.substr(overlap-1, b.length()-overlap);
        // update the overlap region
        //((overlap+1-i)*a+(i*b))/(overlap+1)
        for (int i=1; i<=overlap; i++){
            int posa = a.length()-overlap+i-1;
            int posb = i-1;
            double r = ((overlap+1.-i)*a[posa] + i*b[posb])/(overlap+1);

            char c = (char)round(r);
            s[posa]=c;
        }
        return s;
    }

    vector<string> stitch(vector<string> A, vector<string> B, int overlap){
        vector<string> res (A.size());
        for (int i=0; i<A.size(); ++i)
            res[i] = stitch_s(A[i], B[i], overlap);
        return res;
    }

void testStitch(){
    vector<string> res = stitch({"AAAAAA"},{"JJJJJ"},4);
    print_vector(res);
}
#endif //REVISIONS_STITCH_H
