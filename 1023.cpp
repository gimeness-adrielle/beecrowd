#include <bits/stdc++.h>
using namespace std;

typedef struct consumption{
    int n_residents;
    int n_comsuption;
} Comsuption;

int main (){
    int N;
    int city=1;

    while (cin >> N && N != 0){
        vector<Comsuption>v;
        map<int, int>agroup_comsup;
        int sum_residents=0, sum_comsup=0;

        for (int i=0; i<N; i++){
            Comsuption house, aux;
            cin >> house.n_residents >> house.n_comsuption;
            v.push_back(house);

            int person_consump = house.n_comsuption / house.n_residents;
            agroup_comsup[person_consump] += house.n_residents;

            sum_residents += house.n_residents;
            sum_comsup += house.n_comsuption;
        }

        cout << "Cidade# " << city++ << ':' << '\n';

        int count = 0;
        for (auto i = agroup_comsup.begin(); i != agroup_comsup.end(); ++i) {
            cout << i->second << '-' << i->first;
            if (++count != agroup_comsup.size()) cout << ' ';
        }

        cout << '\n';
        double rate = (double)sum_comsup / sum_residents;
        rate = floor(rate * 100) / 100;
        cout << fixed << setprecision(2);
        cout << "Consumo medio: " << rate << " m3." << '\n';
    }

    return 0;
}