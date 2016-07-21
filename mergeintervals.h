//
// Created by Margot on 7/7/16.
//

#ifndef REVISIONS_MERGEINTERVALS_H
#define REVISIONS_MERGEINTERVALS_H

#include <vector>
#include "utils.h"

using namespace std;


void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

vector<Interval> mergeIntervals(vector<Interval> & v){
    vector<Interval>::iterator it= v.begin();
    while (it != v.end()){
        auto it2 = it+1;
        if (it2 != v.end()){
            if (it->end > it2->start){
                if (it->end <= it2->end){
                    it->end = it2->end;
                    v.erase(it2);
                    return v;
                }
                else{
                    v.erase(it2);
                }
            }
            else it++;
        }
        else{
            return v;
        }
    }
    return v;
}

vector<Interval> insert(vector<Interval> &v, Interval a) {
    if (a.start > a.end) swap(a.start, a.end);
    // Insert based on start
    vector<Interval>::iterator it;
    for (it = v.begin(); it != v.end(); ++it){
        // NOT OVERLAPPING CASES
        if (a.start > it->start && a.start > it->end){
            // nothing go to the next
        }
        else if (a.start < it-> start && a.end < it->start){
            v.insert(it, a);
            return v;
        }
            // OVERLAPPING CASES
        else if (a.start <= it->start || (a.start>it->start && a.start <= a.end)){
            it->start = min(it->start, a.start);
            it->end = max(it->end, a.end);
            return mergeIntervals(v);
        }
    }
    if (it == v.end()){ // insert at the end!
        v.push_back(a);
        return v;
    }
    return v;
}

void testMergeIntervals(){
    vector<Interval> a = {Interval(31,38), Interval(54,76), Interval(87,94)};
    print_vector(a);

}

#endif //REVISIONS_MERGEINTERVALS_H
