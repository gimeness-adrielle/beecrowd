#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<long long,long long>> max_distances = {
    {3, 1},
    {5, 2},
    {11, 4},
    {29, 6},
    {97, 8},
    {127, 14},
    {541, 18},
    {907, 20},
    {1151, 22},
    {1361, 34},
    {9587, 36},
    {15727, 44},
    {19661, 52},
    {31469, 72},
    {156007, 86},
    {360749, 96},
    {370373, 112},
    {492227, 114},
    {1349651, 118},
    {1357333, 132},
    {2010881, 148},
    {4652507, 154},
    {17051887, 180},
    {20831533, 210},
    {47326913, 220},
    {122164969, 222},
    {189695893, 234},
    {191913031, 248},
    {387096383, 250},
    {436273291, 282}
    };
    
    long long N;
    while (cin >> N){
        auto it = upper_bound(max_distances.begin(), max_distances.end(), make_pair(N, LLONG_MAX));
        int idx = it - max_distances.begin();
        cout << max_distances[idx - 1].second << '\n';
    }

    return 0;
}