//
// Created by Costa Bobroff on 07/12/2018.
//

#include "CMatrixGraph.h"


CMatrixGraph::CMatrixGraph(int verticesCount)  {
    AdjacencyMatrix.resize(verticesCount);
    for (int row = 0; row < AdjacencyMatrix.size(); row++) {
        AdjacencyMatrix[row].resize(verticesCount);
        std::fill(AdjacencyMatrix[row].begin(), AdjacencyMatrix[row].end(), 0);
    }
}

CMatrixGraph::CMatrixGraph(IGraph *graph) {
    AdjacencyMatrix.resize(graph->VerticesCount());
    for (int row = 0; row < AdjacencyMatrix.size(); row++) {
        AdjacencyMatrix[row].resize(graph->VerticesCount());
        std::fill(AdjacencyMatrix[row].begin(), AdjacencyMatrix[row].end(), 0);
    }
    for(size_t i = 0;i<graph->VerticesCount();i++){
        std::vector<int> vertices = graph->GetNextVertices(i);
        for(size_t j = 0;j<vertices.size();j++){
            AdjacencyMatrix[i][vertices[j]] = 1;
        }
    }
}

void CMatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < AdjacencyMatrix.size());
    assert(to >= 0 && to < AdjacencyMatrix.size());
    AdjacencyMatrix[from][to] = 1;
}

int CMatrixGraph::VerticesCount() const {
    return AdjacencyMatrix.size();
}

const vector<int> CMatrixGraph::GetNextVertices(int vertex) const  {
    assert(vertex >= 0 && vertex < AdjacencyMatrix.size());
    std::vector<int> vertices;
    for(size_t i = 0;i < AdjacencyMatrix.size();i++){
        if(AdjacencyMatrix[vertex][i] == 1){
            vertices.push_back(i);
        }
    }
    return vertices;
}

const vector<int> CMatrixGraph::GetPrevVertices(int vertex) const{
    assert(vertex >= 0 && vertex < AdjacencyMatrix.size());
    std::vector<int> vertices;
    for(size_t i = 0;i < AdjacencyMatrix.size();i++){
        if(AdjacencyMatrix[i][vertex] == 1){
            vertices.push_back(i);
        }
    }
    return vertices;
}

CMatrixGraph::~CMatrixGraph() = default;