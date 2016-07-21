//
// Created by Margaux Lhommet on 7/3/16.
//

#ifndef REVISIONS_GRAPHLIST_H
#define REVISIONS_GRAPHLIST_H

#include <iostream>
#include <forward_list>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class graphList {
private:
    vector< list<int> > data;
public:
    graphList(int nb):data(vector< list<int>> (nb)){};

    void addEdge(int source, int target){
        data[source].push_back(target);
    }

    void BFS(int start){
        vector<bool> visited(data.size(), false);
        queue<int> frontier;
        frontier.push(start);
        visited[start] = true;

        while (!frontier.empty()){
            int s = frontier.front();
            cout<< s<<" ";
            frontier.pop();
            for (const auto & it : data[s]){
                if (!visited[it]) {
                    visited[it] = true;
                    frontier.push(it);
                }
            }
        }
    }


    void DFS(int start){
        vector<bool> visited(data.size(), false);
        stack<int> frontier;
        frontier.push(start);
        visited[start]=true;

        while (!frontier.empty()){
            int s = frontier.top();
            frontier.pop();
            cout<<s<<" ";
            for (const auto & it: data[s]){
                if (!visited[it]){
                    visited[it]=true;
                    frontier.push(it);
                }
            }
        }
    }

    static void test(){
        graphList g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        cout << "Breadth First Traversal (starting from vertex 2) \n";
        g.BFS(2);
        cout << endl<<"Depth First Traversal (starting from vertex 2) \n";
        g.DFS(2);
    }

};


#endif //REVISIONS_GRAPHLIST_H
