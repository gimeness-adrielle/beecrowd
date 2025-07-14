#include <bits/stdc++.h>
using namespace std;

void split_string (string txt, vector<string> &v){
    string split;
    for (int i=0; i<txt.size(); i++){
        if (txt[i] == ' '){
            v.push_back(split);
            split = "";
        } else
            split += txt[i];
    }
    if (split != "")
        v.push_back(split);
}

int compare_lenght(string a, string b){
    return a.length() > b.length();
}

int main (){
    int N;
    string txt;
    cin >> N;
    getline (cin, txt);

    for (int i=0; i<N; i++){
        vector<string>v;
        getline (cin, txt);
        split_string (txt, v);
        stable_sort(v.begin(), v.end(), compare_lenght);
        int count = 0;
        for (auto s: v){
            cout << s;
            if (++count != v.size())
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}