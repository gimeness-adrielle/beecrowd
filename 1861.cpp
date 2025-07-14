#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string killer, murdered;
    map<string, int>murders_list;
    while (cin >> killer >> murdered){
        if (murders_list[killer] >= 0)
            murders_list[killer]++;
        murders_list[murdered] = -1;
    }

    cout << "HALL OF MURDERERS" << '\n';
    for (auto name: murders_list){
        if (name.second > 0)
            cout << name.first << " " << name.second << '\n';
    }

    return 0;
}