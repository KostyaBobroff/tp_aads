//
// Created by Costa Bobroff on 07/12/2018.
//

#include "CSetGraph.h"


CSetGraph::CSetGraph(int verticesCount) {
    inAdjacencySet.resize(verticesCount);
    outAdjacencySet.resize(verticesCount);
}

CSetGraph::CSetGraph(IGraph *graph) {
    inAdjacencySet.resize(graph->VerticesCount());
    outAdjacencySet.resize(graph->VerticesCount());
    for(size_t i =0;i < inAdjacencySet.size();i++){
        std::vector<int> vertices = graph->GetNextVertices(i);
        for(size_t j = 0;j< vertices.size();j++){
            AddEdge(i, vertices[j]);
        }
    }

}

void CSetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < outAdjacencySet.size());
    assert(to >= 0 && to < outAdjacencySet.size());
    outAdjacencySet[from].insert(to);
    inAdjacencySet[to].insert(from);
}


const vector<int> CSetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < outAdjacencySet.size());
    std::vector<int> vertices;
    vertices.insert(vertices.end(),outAdjacencySet[vertex].begin(), outAdjacencySet[vertex].end());
    return vertices;
}

const vector<int> CSetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < inAdjacencySet.size());
    std::vector<int> vertices;
    vertices.insert(vertices.end(),inAdjacencySet[vertex].begin(), inAdjacencySet[vertex].end());
    return vertices;
}

CSetGraph::~CSetGraph() = default;

int CSetGraph::VerticesCount() const {
    return inAdjacencySet.size();
}