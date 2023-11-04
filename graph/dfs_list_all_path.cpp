/*
    Finding and printing all the path between 2 nodes of a graph
    Inputs:
    1. num of vertex(n);
    2. num of edges(e);
    3. Next e lines will have 2 inputs src and dst

    Output:
    Display total number of paths and print all the paths between first node(0) and 
    last node(size-1)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct Graph{
    int v;
    vector<list<int>> adj;
}G;

void add_edges(G &g, int src, int dst){
    g.adj[src].push_back(dst);
    g.adj[dst].push_back(src);
}

void graph_init(G &g, int num_vertex){
    g.v = num_vertex;
    g.adj.resize(g.v);
}

void dfs(G &g, int start, int end, vector<bool> &visited, list<int> cur_path, vector<list<int>> &paths) {
    visited[start] = 1;
    cur_path.push_back(start);
    
    if(start == end){
        paths.push_back(cur_path);
        return;
    }
    
    for(auto i=g.adj[start].begin(); i!=g.adj[start].end(); i++){
        if(visited[*i] == 0){
            dfs(g, *i, end, visited, cur_path, paths);
            visited[*i] = 0;
        }
    }
}

void print_all_path(vector<list<int>> paths){
    cout<<"Paths: "<<paths.size()<<endl;
    for(int i=0;i<paths.size(); i++){
        for(auto j=paths[i].begin(); j!=paths[i].end(); j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
}

void find_all_path(G &g, int start, int end){
    int size = g.v;
    vector<bool> visited(size,0);
    vector<list<int>> paths;
    list<int> cur_path;
    
    dfs(g,start,end,visited,cur_path,paths);

    print_all_path(paths);
}

int main(){
    G g;
    int num_ver=0, num_edges=0;
    cin>>num_ver;
    cin>>num_edges;
    graph_init(g,num_ver);
    for(int i=0;i<num_edges;i++){
        int src=0,dst=0;
        cin>>src;
        cin>>dst;
        add_edges(g,src,dst);
    }
    find_all_path(g,0,(num_ver-1));
    return 0;
}