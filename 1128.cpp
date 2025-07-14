#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

void DFS (vector<vector<int>> graph, vector<int> &color, int v, stack<int> &s){   
    color[v] = GREY;
    for (auto adj: graph[v])
        if (color[adj] == WHITE)
            DFS (graph, color, adj, s);
    color[v]= BLACK;
    s.push(v);
}

void DFS_kosajaru (vector<vector<int>> graph, vector<int> &color, int v, vector<int> &set){
    color[v] = GREY;
    for (auto adj: graph[v])
        if (color[adj] == WHITE)
            DFS_kosajaru (graph, color, adj, set);
    color[v] = BLACK;
    set.push_back(v);
}

int kosajaru (vector<vector<int>> graph, stack<int>s){
    int V = graph.size();
    vector<int> color(V, WHITE);
    vector<vector<int>>SCC;

    vector<vector<int>> transposed_graph(V);
    for (int i=1; i<V; i++)
        for (auto v: graph[i])
            transposed_graph[v].push_back(i);
    
    while (!s.empty()){
        int v = s.top();
        s.pop();
        if (color[v] == WHITE) {
            vector<int> set;
            DFS_kosajaru(transposed_graph, color, v, set);
            SCC.push_back(set);
        }
    }
    return (SCC.size() == 1) ? 1 : 0;
}

stack<int> DFS_utility (vector<vector<int>> graph){
    int V = graph.size();
    stack<int>s;
    vector<int>color(V, WHITE);

    for (int v=1; v<V; v++)
        if (color[v] == WHITE)
            DFS (graph, color, v, s);
    return s;
}

void add (vector<vector<int>> &graph, int V, int W, int P){
    if (P == 1){
        graph[V].push_back(W);
    } else{
        graph[V].push_back(W);
        graph[W].push_back(V);
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && N != 0 && M != 0){
        vector<vector<int>> graph(N+1);
        for (int i=0; i<M; i++){
            int V, W, P; cin >> V >> W >> P;
            add (graph, V, W, P);
        }
        stack<int>s = DFS_utility(graph);
        int G = kosajaru(graph, s);
        cout << G << '\n';
    }

    return 0;
}