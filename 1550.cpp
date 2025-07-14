#include <bits/stdc++.h>
using namespace std;

int BFS (int A, int B){
    vector<bool>visited(10001, false);
    vector<int> moves(10001, -1);
    queue<int>q;

    visited[A] = true;
    moves[A] = 0;
    q.push(A);

    while (!q.empty()){
        int curr = q.front(); 
        q.pop();

        if (curr == B)
            return moves[curr];
        
        int v1 = curr + 1;
        if (v1 <= 10000 && !visited[v1]) {
            visited[v1] = true;
            moves[v1] = moves[curr] + 1;
            q.push(v1);
        }

        string s = to_string (curr); reverse (s.begin(), s.end());
        int v2 = stoi(s);
        if (v2 <= 10000 && !visited[v2]) {
            visited[v2] = true;
            moves[v2] = moves[curr] + 1;
            q.push(v2);
        }
    }
    return -1;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--){
        int A, B; cin >> A >> B;
        cout << BFS(A, B) << "\n";
    }

    return 0;
}