#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

void DFS (vector<vector<int>>&graph, vector<int>&color, int v, vector<int>&set){
    color[v] = GREY;
    for (auto adj: graph[v]){
        if (color[adj] == WHITE)
            DFS(graph, color, adj, set);
    }
    color[v] = BLACK;
    set.push_back(v);
}

vector<vector<int>> DFS_utility (vector<vector<int>>&graph){
    int size = graph.size();
    vector<int>color(size, WHITE);
    vector<vector<int>>components;

    for (int i=0; i<size; i++){
        if (color[i] == WHITE){
            vector<int>set;
            DFS (graph, color, i, set);
            components.push_back(set);
        }
    }
    return components;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    for (int i=0; i<N; i++){
        int V, E; cin >> V >> E;
        cout << "Case #" << i+1 << ':' << endl;

        vector<vector<int>>graph(V);
        for (int j=0; j<E; j++){
            char v, u; cin >> v >> u;
            graph[v - 'a'].push_back(u - 'a');
            graph[u - 'a'].push_back(v - 'a');
        }

        vector<vector<int>> result = DFS_utility(graph);
        for (int i=0; i<result.size(); i++){
            sort(result[i].begin(), result[i].end());
            for (auto c: result[i]){
                cout << (char)(c + 'a') << ',';
            }
            cout << endl;
        }

        cout << result.size() << " connected components" << endl << endl;
    }

    return 0;
}