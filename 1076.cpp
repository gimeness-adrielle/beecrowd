#include <bits/stdc++.h>
using namespace std;

#define WHITE 0 // not visited
#define GRAY 1 // in process
#define BLACK 2 // finished

typedef struct graph{
    int V;
    vector<vector<int>>adj;
}Graph;

void init (Graph &gr, int V){
    gr.V = V;
    gr.adj.resize(V);
}

void push_gr (Graph &gr, int U, int VER){
    gr.adj[U].push_back(VER);
    gr.adj[VER].push_back(U);
}

void DFS (Graph &gr, int v, vector<int>&color, int &moves){
    color[v] = GRAY;

    for (auto adj: gr.adj[v])
        if (color[adj] == WHITE){
            moves += 2;
            DFS (gr, adj, color, moves);
        }

    color[v] = BLACK;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int i=0; i<T; i++){
        int N; cin >> N;
        int V, A; cin >> V >> A;

        // inicializando grafo
        Graph gr;
        init (gr, V);
        vector<int>color (V, WHITE);
        
        for (int j=0; j<A; j++){
            int U, VER; cin >> U >> VER;
            push_gr(gr, U, VER);
        }
        int moves = 0;
        DFS (gr, N, color, moves);
        cout << moves << '\n';
    }

    return 0;
}