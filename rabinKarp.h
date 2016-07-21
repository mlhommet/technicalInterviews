//
// Created by Margot on 7/15/16.
//

#ifndef REVISIONS_KARP_RABBIN_H
#define REVISIONS_KARP_RABBIN_H

#include <iostream>
using namespace std;

int strStr(const string &haystack, const string &needle) {
    if (needle=="" || haystack=="" || needle.length()>haystack.length()) return -1;
    int n = needle.length();
    int b = 256;
    int m = 101;

    // Compute the initial hash and b^n;
    int h_h=0, h_m=0;
    for (int i=0; i<n; ++i){
        h_h = (b*h_h + haystack[i]) % m;
        h_m = (b*h_m + needle[i]) % m;
    }

    // Compute the value of b^n-1;
    int bn=1;
    for (int i=0; i<n-1; ++i)
        bn = (b*bn) % m;

    // Slide the pattern
    for (int i=0; i<=haystack.length()-n; ++i){
        // If hash matches, check characters one by one - check for collisions!
        if (h_h == h_m){
            int j;
            for (j=0; j<n;++j)
                if (haystack[j+i] != needle[j])
                    break;
            // Pattern found at position i.
            if (j==n) return i;
        }
            // Otherwise slide the pattern by one to the right
        else {
            h_h = (b*(h_h - bn * haystack[i]) + haystack[i + n]) % m;
            if (h_h <0) h_h+=m;
        }
    }
    return -1;
}


void testRabinKarp(){
    string s1 = "ew";
    string s2 = "b";
    cout<<"Test Rabin Karp"<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<"string at position: "<<strStr(s1, s2)<<endl;
    cout<<"End Rabin Karp"<<endl;
}


#endif //REVISIONS_KARP_RABBIN_H
