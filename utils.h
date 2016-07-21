//
// Created by Margot on 6/27/16.
//

#ifndef REVISIONS_SOLUTION_H
#define REVISIONS_SOLUTION_H
#include <iostream>
#include <vector>
using namespace std;

void mySwap(int &a, int &b){
    cout << "here";
    int t = a;
    a = b;
    b=t;
}

template <typename T>
void print_matrix(const vector< vector<T> > & matrix, bool headers=false){
    if (headers) {
        cout << endl << "i/w\t";
        for (int j = 0; j < matrix[0].size(); j++)
            cout << j << '\t';
    }
    for (int i=0; i<matrix.size(); i++){
        cout<<endl;
        if (headers) cout<<i<<'\t';
        for (int j=0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << '\t';
        }
    }
    cout<<endl;
}

template <typename T>
void print_vector(const vector<T> & v, bool header=false){
    if (header){
        cout<<endl;
        for (int i=0; i<v.size();++i){
            cout<<i<<'\t';
        }
        cout<<endl;
    }

    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<'\t';
    cout<<endl;
}

void print_array(int t[], int n){
    cout<<"[";
    for (int i=0; i<n;++i)
        cout<<t[i]<<", ";
    cout<<"]"<<endl;
}


#endif //REVISIONS_SOLUTION_H
