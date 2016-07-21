//
// Created by Margaux Lhommet on 7/8/16.
//

#ifndef REVISIONS_KNIGHTTOUR_H
#define REVISIONS_KNIGHTTOUR_H

#include "utils.h"
#include <vector>
using namespace std;

bool isSafe(int x, int y, const vector<vector<int>>&v){
    return (x>=0 && x<v.size() && y>=0 && y< v[0].size() && v[x][y]==-1);
}

bool solveKT_util(int x, int y, int move, vector<vector<int>> & solution, const vector<int> & movesX, const vector<int> & movesY){
    if (move == solution.size()*solution[0].size()) return true;

    for (int m=0; m<movesX.size(); ++m){
        int nextX = x+movesX[m];
        int nextY = y+movesY[m];
        if (isSafe(nextX, nextY, solution)){
            solution[nextX][nextY]=move;
            if (solveKT_util(nextX,nextY,move+1, solution, movesX,movesY)){
                return true;
            }
            else{
                solution[nextX][nextY]=-1;
            }
        }
    }
    return false;
}

bool solveKT(int nx=8, int ny=8){
    // init solution grid with -1
    vector<vector<int>> solution(nx, vector<int>(ny, -1));
    // valid moves
    vector<int> movesX {2,2,-2,-2,1,1,-1,-1};
    vector<int> movesY {1,-1,1,-1,2,-2,2,-2};
    int x0=0,y0=0;
    solution[x0][y0]=0;
    if(solveKT_util(x0, y0, 1, solution, movesX, movesY)){
        print_matrix(solution);
        return true;
    }
    else{
        cout<<"No solution"<<endl;
        return false;
    }
}



#endif //REVISIONS_KNIGHTTOUR_H
