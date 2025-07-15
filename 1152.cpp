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

long long kruskal (vector<vector<int>>&graph, int n){
    sort(graph.begin(), graph.end());

    vector<int>size(n, 1);
    vector<int>leaders(n);
    for (int i=0; i<n; i++)
        leaders[i] = i;

    long long price=0;
    for (auto e: graph){
        int w = e[0], v=e[1], u=e[2];
        if (find (v, leaders) != find(u, leaders)){
            merge(v, u, leaders, size);
            price += w;
            if (size[u] == n) break;
        }
    }
    return price;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    while (cin >> m >> n && m != 0 && n != 0){
        long long total=0;
        vector<vector<int>>graph;
        for (int i=0; i<n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            total += z;
            graph.push_back({z, x, y});
        }
        long long price = kruskal(graph, m);
        cout << total-price << endl;
    }
    return 0;
}