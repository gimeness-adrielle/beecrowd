#include <bits/stdc++.h>
using namespace std;

const int N = 5;
const vector<pair<int,int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

bool BFS (vector<vector<int>>&graph){
    if (graph[0][0] == 1 || graph[N-1][N-1] == 1)
        return false;
    
    queue<pair<int,int>> q;
    q.push ({0, 0});
    graph[0][0] = 2;

    while (!q.empty()){
        auto [row, col] = q.front(); 
        q.pop();
        if (row == N-1 && col == N-1) return true;

        for (auto [x, y]: directions){
            int move_row = row + x, move_col = col + y;

            if (move_row >= 0 && move_row < N &&
            move_col >= 0 && move_col < N && 
            graph[move_row][move_col] == 0){
                graph[move_row][move_col] = 2;
                q.push ({move_row, move_col});
            }
        }
    }
    return false;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--){
        vector<vector<int>>matrix(5, vector<int>(5));
        for (auto &row: matrix)
            for (auto &num: row)
                cin >> num;
        
        cout << (BFS(matrix) ? "COPS" : "ROBBERS") << endl;
    }

    return 0;
}