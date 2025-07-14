#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, V;
    stack<int>s;
    string cmd;
    cin >> N;
    
    for (int i=0; i<N; i++){
        cin >> cmd;
        if (cmd == "PUSH"){
            cin >> V;
            if (s.empty() || V < s.top())
                s.push(V);
            else
                s.push (s.top());
        }else{
            if (cmd == "POP" && !s.empty())
                s.pop();
            else if (cmd == "MIN" && !s.empty())
                cout << s.top() << endl;    
            else cout << "EMPTY" << endl;
        }
    }
    return 0;
}
