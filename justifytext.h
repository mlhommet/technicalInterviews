//
// Created by Margot on 7/15/16.
//

#ifndef REVISIONS_JUSTIFYTEXT_H
#define REVISIONS_JUSTIFYTEXT_H

#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

string justify(vector<string> & words, int B, bool justify){
    // default values when not justifying
    int nb=1, rest=0;
    // if justify is true, update those values
    if (justify && words.size()>1){
        //compute the number of characters on the line
        int l = 0;
        for (int w=0; w<words.size(); ++w)
            l += words[w].length();
        // number of spaces to distribute
        rest = B-l;
        // number of spaces between each word
        nb = rest/(words.size()-1);
        // number of spaces to distribute first if not evenly divided
        rest = rest%(words.size()-1);
    }

    // transform into a string while inserting spaces between words.
    string s="";
    for (int w=0; w<words.size();++w){
        // insert the word
        s+=words[w];
        // insert spaces if not last word
        if(w<words.size()-1){
            s+= string(nb,' '); // append nb spaces
            //not divided evenly, insert one additional space
            if (rest>0){
                s+=" ";
                rest--;
            }
        }
    }
    s += string(B-s.length(),' ');
    return s;
}

vector<string> fullJustify(vector<string> &A, int B) {
    // Distribute strings on lines
    vector<string> text;
    int charleft = B;
    vector<string> line;
    int i=0;
    while (i < A.size()){
        string w = A[i];
        int lw = w.length();
        //if no room for this word, process the line and create a new line
        if (lw > charleft || charleft<=0){
            //if this is not the last word, transform the line and add it to the results
            if (i < A.size()) text.push_back(justify(line, B, true));
            //otherwise just add the last line without justifying.
            else text.push_back(justify(line, B, false));

            //reset the line
            line.erase(line.begin(), line.end());
            charleft = B;
        }
        //add the word to the line
        line.push_back(w);
        charleft = charleft - w.length()-1;
        i++;
    }
    // words in the buffer
    if (line.size()>0) text.push_back(justify(line, B, false));
    return text;
}

void testJustify(){
//    vector<string> text = {"Hello","this","is","very","fun","obviously."};
//    vector<string> res = fullJustify(text,16);
//    print_vector(res);
    vector<string> text = {"What", "must", "be", "shall", "be."};
    vector<string> res = fullJustify(text,12);
    print_vector(res);
}

#endif //REVISIONS_JUSTIFYTEXT_H
