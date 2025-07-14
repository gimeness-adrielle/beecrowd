#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--){
        string A, B; cin >> A >> B;
        int size = A.size()-B.size();
        string C;
        for (int i=size; i<A.size(); i++)
            C+= A[i];
            
        if (C == B) cout << "encaixa" << endl;
        else cout << "nao encaixa" << endl;
    }

    return 0;
}