/*
 * BFS graph traversal using adjacency matrix to store the graph
*/

#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct graph {
    int **adj;
    int vertex;
};

void add_edge(graph &G, int x, int y){
    G.adj[x][y] = 1;
    G.adj[y][x] = 1;
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
        
        for(int i=0; i<G.vertex;i++)
            if(!visited[i] && g.adj[temp_node][i] == 1){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
   graph g;
   //Initialize
   g.vertex = 5;
   g.adj = (int**)malloc(g.vertex*sizeof(inti*));
   for (int i = 0; i < g.vertex; i++) {
        g.adj[i] = (int*)malloc(g.vertex * sizeof(int));
    }

   add_edge(g, 0, 1);
   add_edge(g, 0, 4);
   add_edge(g, 1, 3);
   add_edge(g, 1, 4);
   add_edge(g, 1, 2);
   add_edge(g, 2, 3);
   add_edge(g, 3, 4);
   bfs(g, 0);
}