#include <iostream>
#include <vector>
#include <queue>





using std::queue;
using std::vector;
using std::cout;

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