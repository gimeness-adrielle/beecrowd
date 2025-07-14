#include <bits/stdc++.h>
using namespace std;

int find (int x, vector<int>&leaders){
    if (leaders[x] == x)
        return x;
    return find(leaders[x], leaders);
}

void merge (int v, int u, vector<int>&leaders, vector<int>&size){
    int a = find (v, leaders);
    int b = find (u, leaders);
    if (size[a] > size[b])
        swap (a, b);
    leaders[a] = b;
    size[b] += size[a];
}

int kruskal_algorithm (vector<vector<int>>&edges, int n){
    sort (edges.begin(), edges.end());

    vector<int>size(n+1, 1);
    vector<int>leaders(n+1);
    for (int i=1; i<n+1; i++)
        leaders[i] = i;
        
    int total=0;
    for (auto e: edges){
        int w = e[0], v = e[1], u = e[2];
        if (find (v, leaders) != find(u, leaders)){
            merge(v, u, leaders, size);
            total += w;
            if (size[u] == n) break;
        }
    }
    return total;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    vector<vector<int>>edges;
    for (int i=0; i<M; i++){
        int V, U, C; cin >> V >> U >> C;
        edges.push_back({C, V, U});
    }
    int total = kruskal_algorithm(edges, N);
    cout << total << endl;

    return 0;
}