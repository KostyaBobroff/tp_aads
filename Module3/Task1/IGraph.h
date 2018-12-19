//
// Created by Costa Bobroff on 06/12/2018.
//

#ifndef TASK1_IGRAPH_H
#define TASK1_IGRAPH_H

#include <vector>
#include <queue>

//using namespace std;
using std::queue;
using std::vector;


struct IGraph {
    virtual ~IGraph()= default;

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;
    //получение кол-во ребер
    virtual int VerticesCount() const  = 0;
    //получение смежных ребер
    virtual const vector<int> GetNextVertices(int vertex) const = 0;
    virtual const vector<int> GetPrevVertices(int vertex) const = 0;
};


#endif //TASK1_IGRAPH_H
