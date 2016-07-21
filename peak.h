//
// Created by Margaux Lhommet on 7/20/16.
//

#ifndef REVISIONS_PEAK_H
#define REVISIONS_PEAK_H

#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

int find_util(vector<int>& nums, int l, int r){
        if (l==r) return r-1;
        int med = l+ (r-l)/2;
        if (l+1==r && nums[med]>nums[med+1])
            return med;
        int expected = nums[0]+med; // expected value at position med;
        if (nums[med]==expected) // the peak is on the right
            return find_util(nums, med+1, r);
        else
            return find_util(nums, l, med); // the peak is on the left
    }

int findPeakElement(vector<int>& nums) {
    return find_util(nums, 0, nums.size()-1);
}

void testPeak(){
    cout<<"Test Find Peak Element"<<endl;
    vector<int> v {1,2,1};
    print_vector(v);
    cout<<findPeakElement(v)<<endl;
    cout<<"End Peak element"<<endl;
}
#endif //REVISIONS_PEAK_H
