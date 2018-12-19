//
// Created by Costa Bobroff on 06/12/2018.
//

#ifndef TASK1_CLISTGRAPH_H
#define TASK1_CLISTGRAPH_H
#include <vector>
#include <queue>
#include "IGraph.h"
//using namespace std;
using std::queue;
using std::vector;


class CListGraph: public IGraph {
public:
    explicit CListGraph(int verticesCount);
    explicit CListGraph(IGraph * graph) ;
    ~CListGraph();
    virtual void AddEdge(int from, int to) ;
    //получение кол-во ребер
    virtual int VerticesCount() const ;
    //получение смежных ребер
    virtual const vector<int> GetNextVertices(int vertex) const ;
    virtual const vector<int> GetPrevVertices(int vertex) const ;
private:
    vector<vector<int>> outAdjacencyLists;
    vector<vector<int>> inAdjacencyLists;
};



#endif //TASK1_CLISTGRAPH_H
