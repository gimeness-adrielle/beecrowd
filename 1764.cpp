#include <bits/stdc++.h>
using namespace std;

int find (int x, vector<int>&leaders){
    if (leaders[x] == x)
        return x;
    return find(leaders[x], leaders);
}

void merge (int x, int y, vector<int>&leaders, vector<int>&size){
    int a = find (x, leaders);
    int b = find (y, leaders);
    if (size[a] > size[b])
        swap (a, b);
    leaders[a] = b;
    size[b] += size[a];
}

int kruskal_algorithm (vector<vector<int>>&edges, int N){
    sort (edges.begin(), edges.end());
    vector<int>size(N, 1);
    
    vector<int>leaders(N);
    for (int i=0; i<N; i++)
        leaders[i] = i;

    int total=0;
    for (auto e: edges){
        int w = e[0], x = e[1], y = e[2];

        if (find(x, leaders) != find(y, leaders)){
            merge(x, y, leaders, size);
            total += w;
            if (size[y] == N) break;
        }
    }
    return total;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    
    int M, N;
    while (cin >> M >> N && M != 0 && N != 0){
        vector<vector<int>>edges;
        for (int i=0; i<N; i++){
            int X, Y, Z; cin >> X >> Y >> Z;
            edges.push_back({Z, X, Y});
        }
        int total = kruskal_algorithm(edges, M);
        cout << total << endl;
    }

    return 0;
}