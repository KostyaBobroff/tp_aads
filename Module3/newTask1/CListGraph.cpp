//
// Created by Costa Bobroff on 06/12/2018.
//

#include "CListGraph.h"

CListGraph::CListGraph(int verticesCount) {
    assert(verticesCount > 0);
    outAdjacencyLists.resize(verticesCount);
    inAdjacencyLists.resize(verticesCount);
}

void CListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < outAdjacencyLists.size());
    assert(to >= 0 && to < outAdjacencyLists.size());
    outAdjacencyLists[from].push_back(to);
    inAdjacencyLists[to].push_back(from);
}

int CListGraph::VerticesCount() const {
    return inAdjacencyLists.size();
}

const vector<int> CListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < outAdjacencyLists.size());
    return outAdjacencyLists[vertex];
}

const vector<int> CListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < outAdjacencyLists.size());
    return inAdjacencyLists[vertex];
}

CListGraph::~CListGraph() = default;

CListGraph::CListGraph(IGraph *graph) {
    inAdjacencyLists.resize(graph->VerticesCount());
    outAdjacencyLists.resize(graph->VerticesCount());

    for(size_t i = 0; i < inAdjacencyLists.size();i++ ){
        vector<int> OldVertices = graph->GetNextVertices(i);
        for(size_t j = 0;j < OldVertices.size() ;j++){
            AddEdge(i, OldVertices[j]);
        }
    }
}

