#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--){
        int f1, f2; cin >> f1 >> f2;
        cout << gcd(f1, f2) << endl;
    }

    return 0;
}