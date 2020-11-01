#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> numbrid{};
ofstream outfile ("loto_numbrid.txt");
int max_arv_numbreid= 20;
int random_arv;


void random_arvud() {

    srand(time(NULL));

    for (int x = 0; x < max_arv_numbreid; x++)
        {
        random_arv = rand() % 80 + 1;
        if (find(numbrid.begin(), numbrid.end(), random_arv) != numbrid.end()) {
            x--;
        } else
        {
            numbrid.push_back(random_arv);
            cout << random_arv << endl;
        }
        }
    sort(numbrid.begin(), numbrid.end(), greater<int>());
    outfile <<"Loto onumbrid on" <<endl;
    for (int x = 0; x < numbrid.size(); x++)
    {
        cout << numbrid[x] <<endl;
        outfile << numbrid[x] <<endl;
    }
        outfile.close();
}
int main()
{
    random_arvud();
    return 0;
}