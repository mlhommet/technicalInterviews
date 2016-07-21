//
// Created by Margaux Lhommet on 6/28/16.
//

#ifndef REVISIONS_EDIT_DISTANCE_H
#define REVISIONS_EDIT_DISTANCE_H

#include <vector>
#include <iostream>
using namespace std;

class Edit_distance {
    /**
     * Return the minimum number of edits between two strings.
     */
    int solve_dp(const string & a, const string & b){
        vector< vector<int> > dp (a.length()+1, vector<int> (b.length()+1,0));
        for (int i=0; i<=a.length(); ++i) {
            dp[i][0] = i;
            for (int j = 0; j <= b.length(); ++j) {
                dp[0][j] = j;
            }
        }
        for (int i=1; i<=a.length(); ++i){
            for (int j=1; j<=b.length(); ++j){
                dp[i][j] = min(
                        1+dp[i-1][j],
                        min(
                        1+dp[i][j-1],
                        (a[i]==b[j] ? 0 : 1) + dp[i-1][j-1]));
            }
        }
        print_matrix(dp);
        return dp[a.length()][b.length()];
    }

public: void test(){
        cout<<"Begin test Edit Distance between two strings:"<<endl;
        string s1("GAATTCAGTTA");
        string s2("GGATCGA");
        cout<<"Edit Cost between "<< s1<< " and " << s2<< ": " <<solve_dp(s1,s2)<<endl;
    }

};


#endif //REVISIONS_EDIT_DISTANCE_H
