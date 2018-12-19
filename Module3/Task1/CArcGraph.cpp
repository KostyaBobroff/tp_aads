//
// Created by Costa Bobroff on 07/12/2018.
//

#include "CArcGraph.h"


CArcGraph::CArcGraph(int verticesCount): count(verticesCount) {}

CArcGraph::CArcGraph(IGraph *graph) {
    count = graph->VerticesCount();
    for(size_t i =0;i<count;i++){
        std::vector<int> vertices = graph->GetNextVertices(i);
        for(int elem:vertices){
            ArcList.emplace_back(i, elem);
        }
    }
}

int CArcGraph::VerticesCount() const {
    return count;
}

void CArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < count);
    assert(to >= 0 && to < count);
    ArcList.emplace_back(from, to);
    count++;
}

const vector<int> CArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex< count);
    std::vector<int> vertices;
    for(const auto &pair:ArcList){
        if(pair.first == vertex){
            vertices.push_back(pair.second);
        }
    }
    return vertices;
}


const vector<int> CArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex< count);
    std::vector<int> vertices;
    for(const auto &pair:ArcList){
        if(pair.second == vertex){
            vertices.push_back(pair.first);
        }
    }
    return vertices;
}

CArcGraph::~CArcGraph() = default;