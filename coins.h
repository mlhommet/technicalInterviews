//
// Created by Margot on 6/27/16.
//

#ifndef REVISIONS_COINS_H
#define REVISIONS_COINS_H

#include <iostream>
#include <vector>
#include "utils.h"

class coins  {

    int solve_coins(const vector<int> & coins, int sum){
        // Initialize the matrix.
        vector<vector<int>> dp (coins.size()+1, vector<int> (sum+1, 0));
        for (int i=0; i<=coins.size(); ++i)
            dp[i][0]=1;
        print_matrix(dp);

        // Build the solution bottom-up.
        for (int i=1; i<=coins.size(); i++){
            int val = coins[i-1];
            for (int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if (val <= j)
                    dp[i][j] += dp[i][j-val];
            }
        }
        // Print and return the solution.
        print_matrix(dp);
        return dp[coins.size()][sum];
    }

    int solve_coins_opt(const vector<int> & coins, int sum){
        // Initialize the array
        vector<int> dp (sum+1, 0);
        dp[0]=1;
       // print_vector(dp);

        for (int i=0; i<coins.size(); ++ i){
            int val = coins[i];
            for (int j=1; j<=sum; ++j){
                if (val <= j)
                    dp[j] +=dp [j-val];
            }
        }
//        print_vector(dp);
        return dp[sum];

    }


public:
    virtual void test(){
        cout<<"Test Coins";
        vector<int> coins {1,2,3};
        int res = solve_coins(coins, 5);
        int res2 = solve_coins_opt(coins, 5);
        cout<<endl<<"max value is "<< res <<" vs " << res2<<endl;
    }
};


#endif //REVISIONS_COINS_H
