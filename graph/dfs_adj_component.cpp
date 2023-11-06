
/*
 * Find number of componets and print the nodes in every component using DFS 
* graph traversal on graph stored using adjacency list
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

void graph_init(graph &g, int num_vertex){
    g.vertex = num_vertex;
    g.adj.resize(g.vertex);
}

void dfs(graph &G, int node, vector<bool> &visited, list<int> &node_list) {
   visited[node] = true;
   node_list.push_back(node);
   //cout<<node<<endl;
   for(auto i=G.adj[node].begin(); i != G.adj[node].end(); i++ ){
        if(!visited[*i]){
            dfs(G, *i, visited,node_list);
        }
   } 
}

void find_comp_print_nodes(graph &G) {
    vector<bool> visited(G.vertex, false);
    int cnt = 0;
    for(int i = 0; i<G.vertex; i++){
        list<int> node_list;
        if(!visited[i]){
            dfs(G,i,visited,node_list);
            cnt++;        
            cout<<"Component "<<cnt<<" nodes: ";
            for(auto i=node_list.begin(); i!=node_list.end(); i++){
                cout<<*i<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Total components: "<<cnt<<endl;
}

int main(){
    graph g;
    int num_ver=0, num_edges=0;
    cin>>num_ver;
    cin>>num_edges;
    graph_init(g,num_ver);
    for(int i=0;i<num_edges;i++){
        int src=0,dst=0;
        cin>>src;
        cin>>dst;
        add_edge(g,src,dst);
    }
    find_comp_print_nodes(g);
    return 0;
}
