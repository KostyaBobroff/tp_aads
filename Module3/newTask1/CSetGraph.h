//
// Created by Costa Bobroff on 07/12/2018.
//

#ifndef TASK1_CSETGRAPH_H
#define TASK1_CSETGRAPH_H

#include "IGraph.h"
#include <vector>
#include <unordered_set>


class CSetGraph: public IGraph {
public:
    explicit CSetGraph(int verticesCount);
    explicit CSetGraph(IGraph * graph) ;
    ~CSetGraph();
    virtual void AddEdge(int from, int to) ;
    //получение кол-во ребер
    virtual int VerticesCount() const ;
    //получение смежных ребер
    virtual const vector<int> GetNextVertices(int vertex) const ;
    virtual const vector<int> GetPrevVertices(int vertex) const ;
private:
    std::vector<std::unordered_set<int>> outAdjacencySet;
    std::vector<std::unordered_set<int>> inAdjacencySet;

};


#endif //TASK1_CSETGRAPH_H
