//
// Created by Costa Bobroff on 07/12/2018.
//

#ifndef TASK1_CMATRIXGRAPH_H
#define TASK1_CMATRIXGRAPH_H

#include "IGraph.h"
#include <vector>


class CMatrixGraph: public IGraph {
public:
    explicit CMatrixGraph(int verticesCount);
    explicit CMatrixGraph(IGraph * graph) ;
    ~CMatrixGraph();
    virtual void AddEdge(int from, int to) ;
    //получение кол-во ребер
    virtual int VerticesCount() const ;
    //получение смежных ребер
    virtual const vector<int> GetNextVertices(int vertex) const ;
    virtual const vector<int> GetPrevVertices(int vertex) const ;
private:
    vector<vector<int>> AdjacencyMatrix;

};




//class CMatrixGraph: public IGraph {
//public:
//    explicit CMatrixGraph(size_t count);
//    explicit CMatrixGraph(IGraph *graph);
//
//    ~CMatrixGraph();
//    virtual void AddEdge(int from, int to);
//    //получение кол-во ребер
//     virtual int VerticesCount() const override;
//    //получение смежных ребер
//     virtual const vector<int> GetNextVertices(int vertex);
//    virtual const vector<int> GetPrevVertices(int vertex);
//
//private:
//    std::vector<std::vector<int>>AdjacencyMatrix;
//
//};


#endif //TASK1_CMATRIXGRAPH_H
