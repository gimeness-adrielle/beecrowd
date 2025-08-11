#include <bits/stdc++.h>
using namespace std;

void DFS (vector<vector<char>> &graph, int row, int col, int N, int M){
    graph[row][col] = 'T';

    if (row-1 > -1 && graph[row-1][col] == 'A')
        DFS (graph, row-1, col, N, M);
    if (col+1 < M && graph[row][col+1] == 'A')
        DFS (graph, row, col+1, N, M);
    if (row+1 < N && graph[row+1][col] == 'A')
        DFS (graph, row+1, col, N, M);
    if (col-1 > -1 && graph[row][col-1] == 'A')
        DFS (graph, row, col-1, N, M);
}

void DFS_utility (vector<pair<int, int>>&T_positions, vector<vector<char>> &graph, int N, int M){
    for (int i=0; i<T_positions.size(); i++){
        int row = T_positions[i].first;
        int col = T_positions[i].second;
        DFS (graph, row, col, N, M);
    }
}

void print (vector<vector<char>> &graph, int N, int M){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cout << graph[i][j];
        cout << endl;
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);

    int N, M;
    while (cin >> N >> M && N != 0 && M != 0){
        vector<vector<char>> graph(N, vector<char>(M));
        vector<pair<int, int>>T_positions;

        for (int i=0; i<N; i++){
            string line; cin >> line;
            for (int j=0; j<M; j++){
                graph[i][j] = line[j];
                if (line[j] == 'T')
                    T_positions.push_back({i, j});
            }
        }
        DFS_utility(T_positions, graph, N, M);
        print (graph, N, M);
        cout << endl;
    }

    return 0;
}