//
// Created by Margaux Lhommet on 7/16/16.
//

#ifndef REVISIONS_GENERATEPALINDROMES_H
#define REVISIONS_GENERATEPALINDROMES_H

#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;


bool isPalindrome(const string & s){
    int start = 0, end = s.length()-1;
    while (start<end){
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void util(const string & A, int start, vector<string> & current, vector<vector<string>> res){
    if (start == A.length()){
        res.push_back(current);
        return;
    }
    for (int i=start; i<A.length(); ++i){
        string s = A.substr(start, i+1);
        if (isPalindrome(s)){
            current.push_back(s);
            util(A, start+1, current, res);
            current.pop_back();
        }
    }
}

vector<vector<string> > partition(string A) {
    vector<vector<string>> res;
    vector<string> curr;
    util(A, 0, curr, res);
    return res;
}

void testPartitionPalindromes(){
    vector<vector<string>> res = partition("aab");
    print_matrix(res);
}

#endif //REVISIONS_GENERATEPALINDROMES_H
