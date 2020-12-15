#include<iostream>
#include<string.h>
#include "string"
#include <fstream>

using namespace std;

int main()
{
    int counter = 0;
    const string filename = ("info.txt");
    ofstream outfile (filename);
    string name;
    cout<< "insert name of the file. correct answer is info.txt" << endl;
    cin >> name ;
    if (name == filename)
    {
        while (counter <=24)
        {
            int random;
            random = rand() % 100 + 1;
            ++counter;
            outfile << random << endl;
        }
        string STRING;
        ifstream infile;
        infile.open (filename);
        while(!infile.eof())
        {
            getline(infile,STRING);
            cout<<STRING <<"  ";
        }
        infile.close();
    }
    else
    {
        cout << "ERROR 1"<< endl;

    }

}