#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

void DFS (vector<vector<int>>&graph, vector<int>&color, int v, stack<int>&s){
    color[v] = GREY;
    for (auto adj: graph[v])
        if (color[adj] == WHITE)
            DFS (graph, color, adj, s);
    color[v] = BLACK;
    s.push(v);
}

stack<int> DFS_utility (vector<vector<int>>&graph){
    int size = graph.size();
    vector<int>color(size, WHITE);
    stack<int>s;

    for (int i=1; i<size; i++)
        if (color[i] == WHITE)
            DFS (graph, color, i, s);
    return s;
}

void DFS_kosaraju (vector<vector<int>>&graph, vector<int>&color, int v, vector<int>set){
    color[v] = GREY;
    for (auto adj: graph[v])
        if (color[adj] == WHITE)
            DFS_kosaraju (graph, color, adj, set);
    color[v] = BLACK;
    set.push_back(v);
}

int kosaraju (vector<vector<int>>&graph, stack<int>&s){
    int size = graph.size();
    vector<vector<int>> SCC;
    vector<int>color(size, WHITE);

    vector<vector<int>>transposed_graph(size);
    for (int i=1; i<size; i++)
        for (auto v: graph[i])
            transposed_graph[v].push_back(i);
    
    while (!s.empty()){
        int v = s.top();
        s.pop();

        if (color[v] == WHITE){
            vector<int>set;
            DFS_kosaraju(transposed_graph, color, v, set);
            SCC.push_back(set);
        }
    }
    return SCC.size();
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<vector<int>>graph(N+1);
    for (int i=0; i<N; i++){
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
    }
    stack<int>s = DFS_utility(graph);
    int result = kosaraju(graph, s);
    if (result == 1){
        cout << 'S' << endl;
    } else
        cout << 'N' << endl;

    return 0;
}