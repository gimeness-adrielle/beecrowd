#include <bits/stdc++.h>
using namespace std;

long long int factorial (long long int n){
    if (n == 1 || n == 0) return 1;
    return n * factorial(n-1);
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    while (cin >> m >> n){
        long long int result = factorial(m) + factorial(n);
        cout << result << endl;
    }

    return 0;
}