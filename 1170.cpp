#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--){
        float C; cin >> C;
        int count=0;
        while (C > 1.0){
            C = C * 0.5;
            count++;
        }
        cout << count << " dias" << endl;
    }

    return 0;
}