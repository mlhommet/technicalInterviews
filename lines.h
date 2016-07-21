//
// Created by Margot on 7/11/16.
//

#ifndef REVISIONS_LINES_H
#define REVISIONS_LINES_H
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int slope(int a_x, int a_y, int b_x, int b_y){
    if (a_x-b_x ==0)
        return 0;
    return (a_y-b_y)/(a_x-b_x);
}

int intercept(int a_x, int a_y, int slope){
    return a_y-(slope*a_x);
}

int maxPoints(vector<int> &A, vector<int> &B) {
    //hashmap that stores count of mapping points for couples <m,i> of slope and intercept
    map<pair<int,int>, int> m;
    for (int a=0; a<A.size()-1;++a){
        int a_x = A[a];
        int a_y = B[a];
        for (int b=a+1; b<A.size(); ++b){
            int b_x = A[b];
            int b_y = B[b];
            int s = slope(a_x,a_y,b_x,b_y);
            int i = intercept(a_x,a_y, s);
            m[pair<int,int>(s,i)]++;
        }
    }
    //return the max of the hashmap
    int max = 0;
    for (auto it = m.begin(); it!=m.end(); ++it)
        if (it->second > max) max = it->second;
    return max;
}



#endif //REVISIONS_LINES_H
