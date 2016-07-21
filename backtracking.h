//
// Created by Margot on 7/8/16.
//

#ifndef REVISIONS_BACKTRACKING_H
#define REVISIONS_BACKTRACKING_H

#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

void permute_util(string s, int start, int end, vector<string> & result){
    if (start == end-1)
        result.push_back(s);
    else{
        for (int i=start; i<end; ++i){
            string ns = s;
            swap(ns[start],ns[i]);
            permute_util(ns, start+1, end, result);
        }
    }
}

vector<string> permuteString(const string & s){
    vector<string> res;
    permute_util(s, 0, s.length(), res);
    print_vector(res);
    return res;
}

bool isPalindrome(const string & s){
    cout<<"test palindrome "<< s <<endl;
    int start = 0, end = s.length()-1;
    while (start<end){
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void util(const string & A, int start, vector<string> & current, vector<vector<string>> & res){
    cout<<"util "<< start << " current= " << current<< endl;
    if (start == A.length()){
        res.push_back(current);
        cout<< "Solution found =" <<current<<endl;
        return;
    }
    for (int i=start; i<A.length(); ++i){
        string s (A, start, start+i+1);
        if (isPalindrome(s)){
            current.push_back(s);
            util(A, start+1, current, res);
            current.pop_back();
        }
    }
}

vector<vector<string> > partitionPalindromes(string A) {
    vector<vector<string>> res;
    vector<string> curr;
    util(A, 0, curr, res);
    return res;
}

void testPartitionPalindromes(string A){
    cout<<"Test palindromes"<<endl;
    cout<<"a = " << isPalindrome("a")<<endl;
    cout<<"ab = " << isPalindrome("ab")<<endl;
    cout<< "aba = "<< isPalindrome("aba")<<endl;
    cout<< "aa = " << isPalindrome("aa")<<endl;

    cout<<"Generate palindromes partition for "<< A<<endl;
    vector<vector<string>> res = partitionPalindromes(A);
    print_vector(res);
    cout<<"END"<<endl;

}
#endif //REVISIONS_BACKTRACKING_H
