//
// Created by Margaux Lhommet on 7/17/16.
//

#ifndef REVISIONS_BLACKSHAPES_H
#define REVISIONS_BLACKSHAPES_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


bool isValid(int x, int y, vector<string> & A){
    return (x>=0 && x<A.size() && y>=0 && y<A[x].size());
}

void print_x(vector<vector<bool>> &visited, vector<string> & A){
    for (int i=0; i<visited.size();++i) {
        for (int j = 0; j < visited[0].size(); ++j) {
            char c = (visited[i][j] == true) ? A[i][j] : '.';
            cout << c << ' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void print_shape(vector<string> & v){
    for (int i=0; i<v.size();++i){
        for (int j=0; j<v[0].size();++j)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
}

void visitShape(int x, int y, vector<string> & A, vector<vector<bool>> & visited, const vector<pair<int,int>>& moves){
    // BFS - Mark self and connected nodes as visited.
    cout<<"visit shape in "<< x<<" "<<y<<endl;
    vector<pair<int, int>> q;
    print_shape(A);
    visited[x][y]=true;
    q.push_back(pair<int, int> (x,y));
    while (!q.empty()){
        pair<int,int> loc = q.back();
        q.pop_back();
        int x=loc.first;
        int y=loc.second;
        cout<<"current "<<x<<' '<<y<<endl;

        for (int i=0; i<moves.size(); ++i){
            // next position
            int nx = x + moves[i].first;
            int ny = y + moves[i].second;

            if (isValid(nx,ny,A)){
//                cout<<"potential :"<<nx<<" "<<ny;
                if (!visited[nx][ny]){
                    cout<< " new ";
                    visited[nx][ny]=true;
                    if (A[nx][ny] == 'X'){
                        cout << "added";
                        q.push_back(make_pair(nx,ny));
                    }
                }
                cout<<endl;
            }
        }
    }
//    cout<<"shape in "<< x<<' '<<y<< " done. "<<endl<<endl;
    print_x(visited, A);
}




int black(vector<string> &A) {
    if (A.size()==0 || A[0].size()==0) return 0;
    int count=0;
    vector<pair<int,int>> validMoves {make_pair(1,0), make_pair(0,1), make_pair(-1,0),make_pair(0,-1)};
    // Iterate over each non visited item.
    vector<vector<bool>> visited (A.size(), vector<bool>(A[0].size(), false));
    for (int row=0; row<A.size(); ++row){
        for(int col=0; col<A[row].size();++col){
            //print_x(visited);
            // If new 'X'
            if (A[row][col] == 'X' && !visited[row][col]){
                // run BFS on the node to mark connected nodes as visited.
                visitShape(row, col, A, visited, validMoves);
                // Increment the black shapes counter.
                count++;
            }
            else{
                visited[row][col]=true;
            }
        }
    }
    return count;
}



void testBlackShapes(){
    vector<string> v ={"XOOOOOXXOX", "OOXXXXOOXX", "XXOXXOOXXO", "OXOXXXXXXO", "XOXXOXOXXX", "OOOOOOOXOO", "XOXXXOOXOX", "XXXOXOXXXO"};
//    vector<string> v ={"OOXO","OXXO","OOOO","OXXO"};
    print_shape(v);
    int res = black(v);
    cout<<"Black Shapes count = "<< res<<endl<<"End test black shapes"<<endl;
}

#endif //REVISIONS_BLACKSHAPES_H
