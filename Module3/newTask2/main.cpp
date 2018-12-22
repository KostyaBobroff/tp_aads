#include <vector>
#include <queue>
#include <iostream>
#include <cassert>


//using namespace std;
using std::queue;
using std::vector;
using std::pair;


//struct IGraph {
//    virtual ~IGraph()= default;
//
//    // Добавление ребра от from к to.
//    virtual void AddEdge(int from, int to) = 0;
//    //получение кол-во ребер
//    virtual int VerticesCount() const  = 0;
//    //получение смежных ребер
//    virtual const vector<int> GetNextVertices(int vertex) const = 0;
//    virtual const vector<int> GetPrevVertices(int vertex) const = 0;
//};
//

class CArcGraph{
public:
    explicit CArcGraph(int verticesCount);
//    explicit CArcGraph(IGraph * graph) ;
    ~CArcGraph();
    void AddEdge(int from, int to) ;
    //получение кол-во ребер
    int VerticesCount() const ;
    //получение смежных ребер
   const vector<int> GetNextVertices(int vertex) const ;
    const vector<int> GetPrevVertices(int vertex) const ;
    int numberOfPaths(int from, int to);
private:
    std::vector<std::pair<int, int>> ArcList;
    size_t count;
};



CArcGraph::CArcGraph(int verticesCount): count(verticesCount) {}

//CArcGraph::CArcGraph(IGraph *graph) {
//    count = graph->VerticesCount();
//    for(size_t i =0;i<count;i++){
//        std::vector<int> vertices = graph->GetNextVertices(i);
//        for(int elem:vertices){
//            ArcList.emplace_back(i, elem);
//        }
//    }
//}
CArcGraph::~CArcGraph() {

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


//pair : first-lengthOfPath, second-pathCount
int CArcGraph::numberOfPaths(int from,int to) {
    vector<pair<int, int>> vertices(VerticesCount());
    queue<int> q;
    q.push(from);
    vertices[from].second = 1;
    while(!q.empty()){
        int startVertice = q.front();
        q.pop();
        vector<int> adjacentVertices = GetNextVertices(startVertice);
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
    CArcGraph graph(n);

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
}