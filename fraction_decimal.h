//
// Created by Margaux Lhommet on 7/20/16.
//

#ifndef REVISIONS_FRACTION_DECIMAL_H
#define REVISIONS_FRACTION_DECIMAL_H

#include <iostream>
#include <vector>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    string res;

    int64_t n = numerator;
    int64_t d = denominator;

    // base case numerator == 0
    if (n==0) return "0";


    // Treat the sign
    if (n <0 ^ d<0)
        res = '-';
    n = abs(n);
    d = abs(d);

    // Treat the integer part
    int64_t integer = n/d;
    res.append(to_string(integer));

    // Treat the decimal part
    int remainder = n%d;
    // no decimal part
    if (remainder == 0 ) return res;

    // decimal part
    res.push_back('.');
    //store the digits
    unordered_map<int,int> m;

    while (remainder > 0){
        // this is not the first time this remainder appears!
        if (m.find(remainder) != m.end()){
            // insert a '(' at the first location
            res.insert(m[remainder], 1, '(');
            res.push_back(')');
            break;
        }
        // remember the first occurence of this digit
        m[remainder] = res.size();
        remainder *=10;
        int digit = remainder / d;
        remainder = remainder % d;
        res.push_back('0'+digit);
    }
    return res;
}


#endif //REVISIONS_FRACTION_DECIMAL_H
