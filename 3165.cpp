#include <bits/stdc++.h>
using namespace std;

vector<int> crivo(int n) {
    vector<bool>isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i*i<=n; i++)
        if (isPrime[i])
            for (int j=i*i; j<=n; j+=i)
                isPrime[j] = false;

    vector<int>prime_nums;
    for (int i=0; i<=n; i++){
        if (isPrime[i]) prime_nums.push_back(i);
    }
    return prime_nums;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int X, Y;
    vector<int>primes = crivo(N);
    int size = primes.size();
    for (int i=size; i>=0; i--){
        if (primes[i] - primes[i-1] == 2){
            X=primes[i];
            Y=primes[i-1];
            break;
        }
    }
    cout << Y << " " <<  X << endl;

    return 0;
}