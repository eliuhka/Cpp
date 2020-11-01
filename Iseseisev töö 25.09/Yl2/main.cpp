#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<float> tulemused{};
string eesnimi;
string perekonnanimi;
float katse;
float vahe;
int max_katsete_arv = 6;
string fail = "tulemused.txt";

void stats() {
    cout << "sisesta oma nimi" << endl;
    cin >> eesnimi >> perekonnanimi;
    ofstream outfile("tulemused.txt");
    outfile << "Nimi:" << endl;
    outfile << eesnimi << " " << perekonnanimi << endl;
    cout << "sisesta oma tulemused " << endl;
    outfile << " " << endl;
    outfile << "Sinu tulemused:" << endl;
    for (int x = 0; x < max_katsete_arv; x++) {
        cin >> katse;
        tulemused.push_back(katse);
        outfile << katse << endl;
    }
    for (int x = 1; x < tulemused.size(); x++) {
        if (tulemused[x - 1] < tulemused[x]) {
            vahe = (tulemused[x] - tulemused[x - 1]);
            cout << "Sinu tulemus oli parem kui eelmine: " << vahe << " meetrit!" << endl;
            cout << tulemused[x] << endl;
        } else if (tulemused[x - 1] > tulemused[x]) {
            vahe = (tulemused[x - 1] - tulemused[x]);
            cout << "Sinu tulemusoli halvem kui eelmine: " << vahe << " meetrit!" << endl;
            cout << tulemused[x] << endl;
        }
    }
    sort(tulemused.begin(), tulemused.end(), greater<int>());
    outfile << "Parim tulemus: " << tulemused[0] << endl;
    outfile << "Teine parim: " << tulemused[1] << endl;
    outfile.close();
}
int main() {
    stats();
    return 0;
}