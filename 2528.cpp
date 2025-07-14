#include <bits/stdc++.h>
using namespace std;

vector<int> BFS (vector<vector<int>>&graph, int src, int dest, int E){
    int size = graph.size();
    vector<bool>visited(size, false);
    vector<int>antecessors(size, -1);
    queue<int>q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(v == dest) return antecessors;

        for (auto adj: graph[v]){
            if (!visited[adj] && adj != E){
                q.push(adj);
                visited[adj] = true;
                antecessors[adj] = v;
            }
        }
    }
    return antecessors;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M){
        vector<vector<int>>graph(N+1);
        for (int i=0; i<M; i++){
            int A, B; cin >> A >> B;
            graph[A].push_back(B);
            graph[B].push_back(A);
        }
        int C, R, E; cin >> C >> R >> E;
        vector<int> result=BFS(graph, C, R, E);
        int count=0;
        while (R != C){
            count++;
            R = result[R];
        }

        cout << count << endl;
    }

    return 0;
}