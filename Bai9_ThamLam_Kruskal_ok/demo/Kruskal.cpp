#include<iostream>
#include<algorithm>
#define SIZE 100
using namespace std;
 
struct Edge {
    int beginVertex, endVertex, weight;
};
 
Edge edges[SIZE*SIZE] = {{0,1,6},{0,2,5},{0,3,4},{1,3,8},{2,3,3},{2,4,2},{3,4,1}};
int vertexNumber = 5;
int edgeNumber = 7;
 
Edge mst[SIZE*SIZE];
int mstNumber;
int parent[SIZE];
 
bool compareEdge(const Edge& e1, const Edge& e2) {
    return (e1.weight < e2.weight);
}
 
int findSet(int u) {
    int v = u;
    while(parent[v] >= 0)
        v = parent[v];
    return v;
}
 
void unionSet(int u,int v) {
    int x = findSet(u);
    int y = findSet(v);
    if (parent[x] > parent[y]){
        parent[y] += parent[x];
        parent[x] = y;
    } else {
        parent[x] += parent[y];
        parent[y] = x;
    }
}
 
void kruskal() {
    int i, beginRoot, endRoot;
 
    for(i=0; i<vertexNumber; i++)
        parent[i] = -1;
 
    sort(edges, edges+edgeNumber, compareEdge);
 
    for(i = 0; i<edgeNumber; ++i) {
        beginRoot = findSet(edges[i].beginVertex);
        endRoot = findSet(edges[i].endVertex);
        if(beginRoot != endRoot) { 
 
            mst[mstNumber++] = edges[i];
            unionSet(beginRoot, endRoot);
            if(mstNumber == vertexNumber - 1) break; 
        }
    }
}
 
int main() {
    kruskal();
 
    int i;
    for(i=0; i<mstNumber; ++i)
        cout<<mst[i].beginVertex<<" "<<mst[i].endVertex<<" "<<mst[i].weight<<endl;
    return 0;
}
