#include <bits/stdc++.h>
using namespace std;

int compare (pair<int,int> a, pair<int,int> b){
    if (a.second != b.second)
        return a.second < b.second;
    return a.first > b.first;
}

int main (){
    string txt;
    bool first=true;

    while (cin >> txt && txt != ""){
        array<int, 128>arr = {0};
        vector<pair<int, int>>v;
        for (auto c: txt){
            arr[(int)c]++;
        }
        
        for (int i = 0; i < 128; ++i) 
            if (arr[i] > 0) 
                v.push_back(make_pair(i, arr[i]));
        
        sort (v.begin(), v.end(), compare);

        if (!first)
            cout << '\n';
        first = false;

        for (auto par: v) 
            cout << par.first << " " << par.second << '\n';
    }

    return 0;
}