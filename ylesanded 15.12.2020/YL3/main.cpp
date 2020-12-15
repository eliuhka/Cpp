#include <iostream>
using namespace std;

int main() {
    int number;
    int counter = 0;
    char *nimi[] = {"erki", "allan", "koit", "martin", "ragnar", "siim", "osvald", "aleks", "fredy", "mark", "hans","rain", "helena", "ami", "mati", "margus", "sven", "kristjan"};
    char **nimistu = nimi;
    char *esimenet2ht;
    char finder;
    cout << "sisesta nime esimene t2ht "<< endl;
    cin >> finder;
    number = sizeof(nimi) / sizeof(char*);
    for(nimistu = nimi; nimistu < nimi + number; nimistu++)
    {
        esimenet2ht = *nimistu;
        if (finder == *esimenet2ht)
        {
            cout << *nimistu << endl;
            counter++;}
    }
    return 0;
}

