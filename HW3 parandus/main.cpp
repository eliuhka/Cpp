#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;


float keskmine_temp(vector<int> &temps)
    {
    int x = 0;
    int summa = 0;
    for (int number:temps)
    {
        summa += number;
        x++;
    }
    return summa/(float)x;
}

float keskmine_temp_ilma_ekstreemumiteta(vector<int> &temps)
    {

    int summa;
    int x = -2;
    summa = -*max_element(temps.begin(), temps.end()) -*min_element(temps.begin(), temps.end());
    for (int number:temps)

    {
        summa += number;
        x++;
    }
    return summa/(float)x;
}

void temperatuurid(string line, vector<int> &temps){
    int index;
    string numbrid ="1234567890";
    index = line.find_first_of(numbrid);
    line = line.substr(index, string::npos);
    string vahe = " ";
    size_t pos = 0;
    string y;
    while ((pos = line.find(vahe)) != string::npos)
    {
        y = line.substr(0, pos);
        temps.push_back(stoi(y));
        line.erase(0, pos + vahe.length());
    }
    temps.push_back(stoi(line));
}

void asukoht(string &line, string &nimi)
{
    int index;
    string numbrid ="1234567890";
    index = line.find_first_of(numbrid);
    nimi = line.substr(0, index-1);
}

void printer(string &nimi, vector<int> &temps)
{
    cout << nimi <<endl;
    cout << "K6rgeim temperatuur: " << *max_element(temps.begin(), temps.end()) << endl;
    cout << "Madalaim temperatuur: " << *min_element(temps.begin(), temps.end()) << endl;
    cout << "Keskmine temperatuur: " << keskmine_temp(temps) << endl;
    cout << "Keskmine temperatuur ilma ekstreemumiteta: " << keskmine_temp_ilma_ekstreemumiteta(temps) << endl;
    temps.clear();
}



int main(){
    vector<int> temps;
    string file_name;
    char vastus;
    string linnanimi;
    string line;
    cout << "Sisesta faili nimi: " << endl;
    cin >> file_name;
    ifstream file (file_name);


    if(file.is_open()){
        getline(file,line);
        asukoht(line, linnanimi);
        temperatuurid(line, temps);
        string nimi= linnanimi;
        for(int i = 1; i < nimi.length(); i++)
        {
            if(nimi[i] == '_')
                nimi[i] = ' ';
        }
        printer(nimi, temps);
        cout << "Kui tahad veel andmeid kirjuta y kui ei n!: " << endl;
        cin >> vastus;

        if (vastus == 'y')
        {
            while(getline(file,line))
            {
                asukoht(line, linnanimi);
                temperatuurid(line, temps);
                printer(linnanimi, temps);
            }
        }
    }
}