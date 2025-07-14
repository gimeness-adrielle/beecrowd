#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

void DFS (vector<vector<int>>&graph, vector<int>&color, int v, int &count){
    color[v] = GREY;
    for (auto adj: graph[v])
        if (color[adj] == WHITE)
            DFS (graph, color, adj, count);
    color[v] = BLACK;
    count++;
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int E, L, i=1;
    while (cin >> E >> L && E != 0 && L != 0){
        cout << "Teste " << i << endl;

        vector<vector<int>>graph(E+1);
        for (int j=0; j<L; j++){
            int X, Y; cin >> X >> Y;
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }

        vector<int>color(E+1, WHITE);
        int count=0;
        DFS (graph, color, 1, count);
        if (count == E)
            cout << "normal" << endl;
        else
            cout << "falha" << endl;
        i++;
        cout << endl;
    }

    return 0;
}