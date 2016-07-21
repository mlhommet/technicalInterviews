//
// Created by Margot on 7/1/16.
//

#ifndef REVISIONS_GRAPHPOINTER_H
#define REVISIONS_GRAPHPOINTER_H

#include <list>
using namespace std;

class GraphPointer {
private:
    int v;
    list<int> * adj;

public:
    Graph(int v):v(v),adj(new list<int>(v)){};

    void addEdge(int src, int dst){

    }


};


#endif //REVISIONS_GRAPHPOINTER_H
