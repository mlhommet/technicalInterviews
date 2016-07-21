//
// Created by Margot on 6/27/16.
//

#ifndef REVISIONS_FROG_H
#define REVISIONS_FROG_H

#include <vector>
#include <iostream>
using namespace std;

class Frog {

    int solve_frog2D(int step_max, int target, int q){
        vector<vector<int>> v (step_max+1, vector<int> (target +1,0));
        for (int s=0; s<=step_max; ++s)
            v[s][0]=1;
        for (int s=1; s<=step_max; ++s){
            for (int d=1; d<=target; ++d){
                v[s][d] = v[s-1][d];
                if (s<=d)
                    v[s][d] = (v[s-1][d] + v[s][d-s]) % q;

            }
        }
        return v[step_max][target];
    }

    int solve_frog1D(int step_max, int target, int q){
        vector<int> v (target +1,0);
        v[0]=1;
        for (int s=1; s<=step_max; ++s){
            for (int d=1; d<=target; ++d){
                if (s<=d)
                    v[d] = (v[d] + v[d-s]) % q;

            }
        }
        return v[target];
    }

public:
    int test(){
        cout<<"Begin test FROG"<<endl;
        int final = 4;
        int steps = 2;
        int res1 = solve_frog2D(steps, final, 1000);
        int res2 = solve_frog1D(steps, final, 1000);
        cout<<res1<<endl << res2<<endl;
    }
};


#endif //REVISIONS_FROG_H