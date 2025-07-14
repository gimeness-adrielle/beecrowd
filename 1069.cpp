#include <bits/stdc++.h>
using namespace std;

int diamonds_count (string terrain, stack<char> &s){
    int diamonds=0;
    for (auto c:terrain){
        if (c == '<')
            s.push(c);
        else if (c == '>'){
            if (!s.empty()){
                s.pop();
                diamonds++;
            }
        }
    }
    return diamonds;
}

int main (){
    int N;
    string terrain;
    cin >> N;

    for (int i=0; i<N; i++){
        stack<char>s;
        cin >> terrain;
        cout << diamonds_count(terrain, s) << '\n';
    }
}