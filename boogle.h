//
// Created by Margot on 7/12/16.
//

#ifndef REVISIONS_BOOGLE_H
#define REVISIONS_BOOGLE_H

//Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
//boggle[][]   = {{'G','I','Z'},
//{'U','E','K'},
//{'Q','S','E'}};
//isWord(str): returns true if str is present in dictionary
//else false.
//
//Output:  Following words of dictionary are present
//        GEEKS
//QUIZ

#include <vector>
#include <iostream>
using namespace std;

bool isWord(const vector<string> & dic, const string & s){
    return (find(dic.begin(),dic.end(),s) != dic.end());
}

void boggle_util(vector<vector<char>> boggle, vector<string> & res,
                 const vector<string> & dic, vector<vector<bool>> visited, int i, int j, string s){
    visited[i][j]=true;
    s+=boggle[i][j];
    if (isWord(dic, s))
        res.push_back(s);
    //recurr on adjacent cells
    for (int row = i-1; row<=i+1; ++row) {
        for (int col = j - 1; col <= j + 1; ++col) {
            if (row>=0 && row<boggle.size() && col>=0 && col <boggle[0].size() && !visited[row][col])
                boggle_util(boggle, res, dic, visited, row, col, s);
        }
    }
}

vector<string> playboggle(vector<vector<char>> boggle, const vector<string> & dic){
    vector<string> res;
    vector<vector<bool>> visited (boggle.size(), vector<bool>(boggle.size(), false));
    for (int i=0; i<boggle.size();++i){
        for (int j=0; j<boggle[0].size();++j) {
            boggle_util(boggle, res, dic, visited, i, j, "");
        }
    }
    return res;
}

void testBoggle(){
    vector<vector<char>> boggle {{'G','I','Z'}, {'U','E','K'}, {'Q','S','E'}};
    vector<string> dic {"GEEKS", "FOR", "QUIZ", "GO"};
    vector<string> result = playboggle(boggle, dic);
    print_vector(result);
}



#endif //REVISIONS_BOOGLE_H
