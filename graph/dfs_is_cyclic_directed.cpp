/*
    Finding and printing any one cycles present in the directed graph
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

//Directed graph
void add_edges(G &g, int src, int dst){
    g.adj[src].push_back(dst);
}

void graph_init(G &g, int num_vertex){
    g.v = num_vertex;
    g.adj.resize(g.v);
}

int dfs(G &g, int start, vector<bool> cur_vis_path, vector<bool> &visited, list<int> &path) {
    visited[start] = 1;
    cur_vis_path[start] = 1;
    path.push_back(start);
    
    for(auto i=g.adj[start].begin(); i!=g.adj[start].end(); i++){
        if(visited[*i] == 0){
            if(1 == dfs(g, *i, cur_vis_path, visited, path)){
                return 1;
            } 
        }else if(visited[*i] == cur_vis_path[*i]){
            path.push_back(*i);
            return 1;
        }
    }
    path.pop_back();
    return 0;
}

void print_circular_path(list<int> path){
    int last = path.back();
    bool first_element = 0;
    for(auto j=path.begin(); j!=path.end(); j++){
        if(!first_element){
            if(last == *j){
                first_element=1;
                cout<<last<<" ";
            }
        }else {
            cout<<*j<<" ";
        }
    }
    cout<<endl;
}

void find_and_print_a_cycle(G &g, int start, int end){
    int size = g.v;
    bool is_cycle = 0;
    vector<bool> visited(size,0);
    vector<bool> cur_vis_path(size,0);
    list<int> path;
    for(int i=0; i<size;i++) {
        if(dfs(g,start,cur_vis_path,visited,path)){
            cout<<"graph has cycles"<<endl;
            is_cycle = 1;
            break;
        }
    }
    if(is_cycle == 1){
        print_circular_path(path);
    } else {
        cout<<"graph has no cycle"<<endl;
    }
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
    find_and_print_a_cycle(g,0,(num_ver-1));
    return 0;
}
