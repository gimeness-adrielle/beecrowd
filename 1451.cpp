#include <bits/stdc++.h>
using namespace std;

int main (){
    string txt;
    list<char>l;

    while (cin >> txt){
        list<char>l;
        auto it = l.begin();

        for (auto c: txt){
            if (c == '[')
                it = l.begin();
            else if (c == ']')
                it = l.end();
            else 
                l.insert (it, c);
        }
        for (auto c: l){
            cout << c;
        }
        cout<< endl;
    }   
    return 0;
}