#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int hashmat, enemy;
    while (cin >> hashmat >> enemy){
        if (hashmat < enemy)
            cout << enemy - hashmat << endl;
        else
            cout << hashmat - enemy << endl;
    }

    return 0;
}