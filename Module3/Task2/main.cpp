#include <vector>
#include <queue>
#include <iostream>
#include <cassert>
#include <unordered_set>

//using namespace std;
using std::queue;
using std::vector;
using std::pair;

struct IGraph {
    virtual ~IGraph()= default;

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;
    //получение кол-во ребер
    virtual int VerticesCount() const  = 0;
    //получение смежных ребер
    virtual const vector<int> GetAdjacentVertices(int vertex) const = 0;
};

class CListGraph: public IGraph {
public:
    explicit CListGraph(int verticesCount);
    explicit CListGraph(IGraph * graph) ;
    ~CListGraph();
    virtual void AddEdge(int from, int to) ;
    //получение кол-во ребер
    virtual int VerticesCount() const ;
    //получение смежных ребер
    virtual const vector<int> GetAdjacentVertices(int vertex) const ;
    int numberOfPaths(int from,int to);

private:
    vector<vector<int>> AdjacencyLists;

};


CListGraph::CListGraph(int verticesCount) {
    assert(verticesCount > 0);
    AdjacencyLists.resize(verticesCount);
}

void CListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < AdjacencyLists.size());
    assert(to >= 0 && to < AdjacencyLists.size());
    AdjacencyLists[from].push_back(to);
    AdjacencyLists[to].push_back(from);
}

int CListGraph::VerticesCount() const {
    return AdjacencyLists.size();
}

const vector<int> CListGraph::GetAdjacentVertices(int vertex) const  {
    assert(vertex >= 0 && vertex < AdjacencyLists.size());
    return AdjacencyLists[vertex];
}


CListGraph::~CListGraph() = default;

CListGraph::CListGraph(IGraph *graph) {
    AdjacencyLists.resize(graph->VerticesCount());

    for(size_t i = 0; i < AdjacencyLists.size();i++ ){
        vector<int> OldVertices = graph->GetAdjacentVertices(i);
        for(size_t j = 0;j < OldVertices.size() ;j++){
            AddEdge(i, OldVertices[j]);
        }
    }
}

//pair : first-lengthOfPath, second-pathsCount
int CListGraph::numberOfPaths(int from,int to) {

    vector<pair<int, int>> vertices(VerticesCount(), pair<int, int>(0,0));
    queue<int> q;
    q.push(from);
    vertices[from].second = 1;
    while(!q.empty()){
        int startVertice = q.front();
        q.pop();
        vector<int> adjacentVertices = GetAdjacentVertices(startVertice);
        for(int i : adjacentVertices ){
            if(vertices[i].second == 0){
                vertices[i].first = vertices[startVertice].first + 1;
                vertices[i].second = vertices[startVertice].second;
                q.push(i);
            }else if(vertices[i].first == vertices[startVertice].first + 1){
                vertices[i].second += vertices[startVertice].second;
            }
        }
    }
    return vertices[to].second;
}

int main()
{
    unsigned int n = 0;
    std::cin >> n;
    CListGraph graph(n);

    int k;
   std::cin >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        std::cin >> a >> b;
        graph.AddEdge(a, b);
    }

    int from = 0;
    int to = 0;
    std::cin >> from >> to;

    std::cout << graph.numberOfPaths(from, to);
    return 0;
}