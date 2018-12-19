//
// Created by Costa Bobroff on 07/12/2018.
//

#ifndef TASK1_CARCGRAPH_H
#define TASK1_CARCGRAPH_H

#include "IGraph.h"
#include <vector>


class CArcGraph: public IGraph {
public:
    explicit CArcGraph(int verticesCount);
    explicit CArcGraph(IGraph * graph) ;
    ~CArcGraph();
    virtual void AddEdge(int from, int to) ;
    //получение кол-во ребер
    virtual int VerticesCount() const ;
    //получение смежных ребер
    virtual const vector<int> GetNextVertices(int vertex) const ;
    virtual const vector<int> GetPrevVertices(int vertex) const ;
private:
    std::vector<std::pair<int, int>> ArcList;
    size_t count;
};


#endif //TASK1_CARCGRAPH_H
