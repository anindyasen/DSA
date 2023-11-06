
/*
 * DFS graph traversal using adjacency list to store the graph
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct graph {
    vector<list<int>> adj;
    int vertex;
};

void add_edge(graph &G, int x, int y){
    G.adj[x].push_back(y);
    G.adj[y].push_back(x);
}

void dfs(graph &G, int node, vector<bool> &visited) {
   visited[node] = true;
   cout<<node<<endl;
   for(auto i=G.adj[node].begin(); i != G.adj[node].end(); i++ ){
        if(!visited[*i]){
            dfs(G, *i, visited);

        }
   } 
}

void graph_traversal(graph &G, int start) {
    vector<bool> visited(G.vertex, false);
    dfs(G,start,visited);
}

int main()
{
   graph g;
   //Initialize
   g.adj.resize(5);
   g.vertex = 5;

   add_edge(g, 0, 1);
   add_edge(g, 0, 4);
   add_edge(g, 1, 3);
   add_edge(g, 1, 4);
   add_edge(g, 1, 2);
   add_edge(g, 2, 3);
   add_edge(g, 3, 4);
   graph_traversal(g, 0);
}
