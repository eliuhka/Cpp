#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string line;
    string failinimi;
    int ridade_arv = 0;
    cout<<"insert name of the fail(info.txt)"<<endl;
    cin>>failinimi;
    ifstream myfile(failinimi);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << '\n';
            ++ridade_arv;
        }
        myfile.close();
        cout << "files oli " << ridade_arv << " rida" << endl;
    } else cout << "unable to open or find the file";
}
