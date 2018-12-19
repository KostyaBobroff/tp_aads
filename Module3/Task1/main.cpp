#include <iostream>
#include <vector>
#include <queue>
#include "IGraph.h"
#include "CListGraph.h"
#include "CMatrixGraph.h"
#include "CSetGraph.h"
#include "CArcGraph.h"


using std::queue;
using std::vector;
using std::cout;

//
//
//class ListGraph : public IGraph{
//public:
//    explicit ListGraph(int verticesCount);
////    ListGraph(IGraph * graph);
////    ~ListGraph();
//    virtual void AddEdge(int from, int to) ;
//    //получение кол-во ребер
//    virtual int VerticesCount() const ;
//    //получение смежных ребер
//    virtual const vector<int> GetNextVertices(int vertex) const ;
//    virtual const vector<int> GetPrevVertices(int vertex) const ;
//private:
//    vector<vector<int>> outAdjacencyLists;
//    vector<vector<int>> inAdjacencyLists;
//};
//
//ListGraph::ListGraph(int verticesCount) {
//    assert(verticesCount > 0);
//    outAdjacencyLists.resize(verticesCount);
//    inAdjacencyLists.resize(verticesCount);
//}
//
//void ListGraph::AddEdge(int from, int to) {
//    assert(from >= 0 && from < outAdjacencyLists.size());
//    assert(to >= 0 && to < outAdjacencyLists.size());
//    outAdjacencyLists[from].push_back(to);
//    inAdjacencyLists[to].push_back(from);
//}
//
//int ListGraph::VerticesCount() const {
//    return inAdjacencyLists.size();
//}
//
//const vector<int> ListGraph::GetNextVertices(int vertex) const {
//    assert(vertex >= 0 && vertex < outAdjacencyLists.size());
//    return outAdjacencyLists[vertex];
//}
//
//const vector<int> ListGraph::GetPrevVertices(int vertex) const {
//    assert(vertex >= 0 && vertex < outAdjacencyLists.size());
//    return inAdjacencyLists[vertex];
//}
//

void BFS(const IGraph* graph,int vertex ,void (*visit) (int) ){
    vector<bool> isQueued(graph->VerticesCount(), false);
    queue<int> greyVertices;
    isQueued[vertex] = true;
    greyVertices.push(vertex);
    while(!greyVertices.empty()){
        int currentVertex = greyVertices.front();
        visit(currentVertex);
        greyVertices.pop();
        const vector<int>& outVerteces = graph->GetNextVertices(currentVertex);
        for(int i =0;i< outVerteces.size(); i++){
            if(!isQueued[outVerteces[i]]){
                isQueued[outVerteces[i]] = true;
                greyVertices.push(outVerteces[i]);
            }
        }
    }
}

int main() {
    IGraph *graph = new CListGraph(5);
    graph->AddEdge(0,2);
    graph->AddEdge(0,3);
    graph->AddEdge(1,0);
    graph->AddEdge(1,3);
    graph->AddEdge(2,1);
    graph->AddEdge(2,4);
    graph->AddEdge(3,4);
    BFS(graph, 0 , [](int vertex){cout<<vertex<<" ";});
    std::cout<<std::endl;
    IGraph *grapher = new CMatrixGraph(graph);
    BFS(graph, 0 , [](int vertex){cout<<vertex<<" ";});
    std::cout<<std::endl;
    IGraph * graphSet = new CSetGraph(grapher);
    BFS(graphSet, 0 , [](int vertex){cout<<vertex<<" ";});
    std::cout<<std::endl;
    IGraph * graphArc = new CArcGraph(graph);
    BFS(graphArc, 0 , [](int vertex){cout<<vertex<<" ";});
    delete graph;
    delete grapher;
    delete graphSet;
    delete graphArc;

    return 0;
}