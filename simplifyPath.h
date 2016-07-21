//
// Created by Margaux Lhommet on 7/19/16.
//

#ifndef REVISIONS_SIMPLIFYPATH_H
#define REVISIONS_SIMPLIFYPATH_H

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include "utils.h"
using namespace std;

vector<string> splitString(string & A, char c){
    vector<string> res;
    int i = 0;
    int j = A.find(c);
    while (j != string::npos) {
        if (i < j)
            res.push_back(A.substr(i, j - i));
        i = ++j;
        j = A.find(c, j);
    }

    if (i<A.length())
        res.push_back(A.substr(i, A.length()-i));

    return res;
}

string simplifyPath(string A) {
    vector<string> v = splitString(A, '/');
    stack<string> s;

    // Analyze the path
    for (auto & it: v){
        if (it ==".."){
            if (!s.empty())
                s.pop();
        }
        else if (it == "."){}
        else s.push(it);
    }

    // Reconstruct the string from the stack
    if (!s.empty()) {
        string res="";
        while (!s.empty()) {
            res.insert(0,"/" + s.top());;
            s.pop();
        }
        return res;
    }
    else return "/";
}

void testSplitString(){
    string s = "Hello////this is lilo ////";
    vector<string> v = splitString(s,'/');
    print_vector(v);
}

void testSimplifyPath(){
    string s = "/aqu/erf/./koz/../b/";
    string res = simplifyPath(s);
    cout<<s<<endl;
    cout<< res<<endl;
}


#endif //REVISIONS_SIMPLIFYPATH_H
