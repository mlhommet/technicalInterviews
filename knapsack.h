//
// Created by Margot on 6/27/16.
//

#ifndef REVISIONS_KNAPSACK_H
#define REVISIONS_KNAPSACK_H

#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

class knapsack{

    int solve_knapsack_noRep(const vector<int> &vals, const vector<int> &weights, int maxWeight){
        vector< vector<int> > dp (vals.size()+1, vector<int> (maxWeight+1, 0));
        for (int i=1; i <= vals.size(); i++){
            for (int total_weight=1; total_weight <= maxWeight; total_weight ++){
                dp[i][total_weight] = dp[i-1][total_weight];
                int w = weights[i-1];
                int v = vals[i-1];
                if (total_weight - w >= 0){
                    dp[i][total_weight] = max(dp[i][total_weight], dp[i-1][total_weight-w]+v);
                }
            }
        }
        print_matrix(dp);
        return dp[vals.size()][maxWeight];
    }

    int solve_knapsack_Rep(const vector<int> &vals, const vector<int> &weights, int maxWeight){
        vector<int> dp (maxWeight+1,0);
        for (int w=1; w<=maxWeight; ++w ){
            dp[w] = dp[w-1]; // cannot not take
            for (int i=0; i<vals.size(); i++){
                if (weights[i] <= w) // can take
                    dp[w] = max(dp[w], dp[w-weights[i]]+vals[i]); // select the max
            }
        }
        print_vector(dp);
        return dp[maxWeight];
    }

    int solve_knapsack_rec(const vector<int> &vals, const vector<int> &weights, int maxWeight){
        vector<int> dp (maxWeight+1,-1);
        dp[0]=0;
        return knapsack_rec_aux(vals, weights, maxWeight, dp);
    }

    int knapsack_rec_aux(const vector<int> &vals, const vector<int> &weights, int w, vector<int> & dp){
        cout<<"w = " << w;
        if (0 <= dp[w]) {
            cout<<" in memory =" << dp[w]<<endl;
            print_vector(dp);
            return dp[w];
        }
        else{
            cout << " search "<< endl;
            dp[w]=0;
            for (int i=0; i<vals.size(); ++i){
                if (weights[i]<=w)
                    dp[w]= max(dp[w], knapsack_rec_aux(vals, weights, w-weights[i], dp)+vals[i]);
                cout<<"w = "<< w <<" done == "<<dp[w]<<endl;
            }
        }
    }

public:
    virtual void test(){
        cout<<"Test Knapsack";
        vector<int> weights {6,3,4,2};
        vector<int> vals {30,14,16,9};
        int norep = solve_knapsack_noRep(vals, weights, 10);
        int rep = solve_knapsack_Rep(vals, weights, 10);
        int rec = solve_knapsack_rec(vals, weights, 10);
        cout<<endl<<"max value of the bag without repetitions is "<< norep;
        cout<<endl<<"max value of the bag with repetitions is "<< rep<<endl;
        cout<<endl<<"max value of the bag with repetitions and memoization is "<< rec<<endl;

    }
};


#endif //REVISIONS_KNAPSACK_H
