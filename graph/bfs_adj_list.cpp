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

void bfs(graph &G, int start) {
    bool visited[G.vertex];
    queue<int> q;
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int temp_node = q.front();
        cout<<temp_node<<endl;
        q.pop();
        for(auto i = G.adj[temp_node].begin(); i != G.adj[temp_node].end(); i++) {
            if(!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
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
   bfs(g, 0);
}