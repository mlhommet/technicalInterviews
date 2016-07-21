//
// Created by Margaux Lhommet on 7/10/16.
//

#ifndef REVISIONS_ERATOSTHENES_H
#define REVISIONS_ERATOSTHENES_H

#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(int n){
    vector<bool> prime (n+1,true);
    for (int i=2; i<=sqrt(n); ++i){
        if (prime[i]){
            for (int j=i*i; j<=n; j+=i)
                prime[j]=false;
        }
    }
    return prime;
}

#endif //REVISIONS_ERATOSTHENES_H
