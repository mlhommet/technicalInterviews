//
// Created by Margaux Lhommet on 7/8/16.
//

#ifndef REVISIONS_BACK_MAZE_H
#define REVISIONS_BACK_MAZE_H

#include <vector>
#include "utils.h"
using namespace std;

bool legal(int x, int y, const vector<vector<int>> & maze){
    return (x>=0 && x<maze.size() && y>=0 && y<maze[0].size() && maze[x][y]==1);
}

bool solveMaze_util(const vector<vector<int>> & maze, vector<vector<int>> & solution, int x=0, int y=0){
    if (x==maze.size()-1 && y==maze[0].size()-1) {
        solution[y][y]=1;
        return true;
    }
    //otherwise try possible moves
    solution[x][y]=1;
    if ((legal(x+1,y, maze) && (solveMaze_util(maze, solution, x+1, y))) ||
        (legal(x, y+1, maze) && (solveMaze_util(maze, solution, x, y+1))))
        return true;
    else {
        solution[x][y]=0;
        return false;
    }
}

vector<vector<int>> solveMaze(vector<vector<int>> & maze){
    vector<vector<int>> solution (maze.size(), vector<int> (maze[0].size(), 0));
    if (solveMaze_util(maze, solution, 0, 0)) {
        print_matrix(solution);
        return solution;
    }
    else {
        cout << "no solution";
        return vector<vector<int>>();
    }
}

void testMaze(){
    vector<vector<int>> maze{ {1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 0, 0},
                             {1, 1, 1, 1}};
    print_matrix(maze);
    solveMaze(maze);
}


#endif //REVISIONS_BACK_MAZE_H
