#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

bool DFS (vector<vector<int>> &graph, vector<int> &color, int v){
    color[v] = GREY;

    for (auto adj: graph[v]){
        if (color[adj] == WHITE){
            if (DFS (graph, color, adj)) return true;
        }
        else if (color[adj] == GREY){ 
            return true;
        }
    }

    color [v] = BLACK;
    return false;
}

bool DFS_utility (vector<vector<int>> &graph, vector<int> &color){
    int V = graph.size();
    for (int i=0; i<V; i++)
        if (color[i] == WHITE)
            if (DFS(graph, color, i)) return true;

    return false;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<vector<int>> graph(N);
        vector<int> color(N, WHITE);

        for (int i=0; i<M; i++){
            int A, B; cin >> A >> B;
            graph[A-1].push_back(B-1);
        }
        if (DFS_utility(graph, color))
            cout << "SIM\n";
        else
            cout << "NAO\n";
    }
    return 0;
}