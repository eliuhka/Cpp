#include<iostream>
#include<string.h>
#include "string"

using namespace std;
int main()
{
    string name;
    int age;
    string gender;

    cout << "insert your gender m/f" << endl;
    cin >> gender;
    cout << "insert your age" << endl;
    cin >> age;
    cout << "insert your name" << endl;
    cin >> name;


    if (gender=="f")
    {
        cout << name << endl;
        cout <<"current age is "<< age << endl;
        while (age < 61)
        {
            ++age;
            ++age;
            ++age;
            ++age;
            ++age;
            if (age <= 60) {
                cout << age << "  ";
            }
            else {
                cout<< endl;
            }}}
    if (gender=="m")
    {
        cout << name << endl;
        cout <<"current age is "<< age << endl;
        while (age < 66)
        {
            ++age;
            ++age;
            ++age;
            ++age;
            ++age;
            if (age <= 65) {
                cout << age << "  ";
            }
            else {
                cout << endl;
            }}}}