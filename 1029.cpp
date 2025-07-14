#include <bits/stdc++.h>
using namespace std;

int fibonacci (int n, int &calls){
    calls++;
    if (n <= 1)
        return n;
    return fibonacci(n-1, calls) + fibonacci(n-2, calls);
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    for (int i=0; i<N; i++){
        int x; cin >> x;
        int calls = -1;
        int result = fibonacci(x, calls);
        cout << "fib(" << x << ") = " << calls << " calls = " << result << endl;
    }

    return 0;
}