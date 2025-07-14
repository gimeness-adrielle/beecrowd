#include <bits/stdc++.h>
using namespace std;

int BFS (map<string, vector<string>>&graph, string src, string dest){
    int V = graph.size();
    queue<pair<string, int>>q;
    map<string, bool> visited;

    q.push ({src, 0});
    visited[src] = true;

    while (!q.empty()){
        auto [v, w] = q.front();
        q.pop();

        if (v == dest) return w;

        for (string adj: graph[v]){
            if (!visited[adj]){
                visited[adj] = true;
                q.push ({adj, w+1});
            }
        }
    }
    return -1;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E; cin >> V >> E;
    map<string, vector<string>>graph;
    for (int i=0; i<E; i++){
        string v, u; cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    int res = BFS(graph, "Entrada", "*");
    res += BFS(graph, "*", "Saida");

    cout << res << endl;

    return 0;
}