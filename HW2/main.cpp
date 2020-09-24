#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int choice;
    string number;
    string number2;
    bool game_enabled;


    int raha = 0;

    mt19937 generator;
    generator.seed(time(0));

    uniform_int_distribution<uint32_t> suva(1, 100000);
    int random = suva(generator);
    random = suva(generator);
    cout << random << endl;
    int oige_number;
    oige_number = random;
    game_enabled = true;


    cout << "Want to win a million dollars?" << endl;
    cout << "If so, guess the winning number (a number between 0 and 100000)" << endl;
    cout << "insert $1.00 and enter your number or press type 'q' for quiting" << endl;
    cin >> number;

        while (game_enabled) {


            if (number == "q") {
                cout << "Exiting game.....Good bye" << endl;
                cout << "u spent " << raha << " euros" << endl;
                game_enabled = false;

            } else {
                int i = stoi(number);
                cout << i << endl;
                if (i == oige_number) {
                    cout << "YOU WON!";
                    game_enabled = false;
                } else {
                    char yesno;
                    ++raha;
                    cout
                            << "Sorry, good guess, but not quite right. Do you want me to give you a hint for 2 euros (y|n)?"
                            << endl;
                    cout << "if u want to continue without a hint type n and pay 1 euro";
                    cin >> yesno;
                    if (yesno == 'y') {
                        ++raha;
                        ++raha;

                        if (i < oige_number) {
                            cout << i << " is smaller then correct number" << endl;
                            cout << "Insert $1.00 and enter your number or 'q' to quit:";
                            cin >> number;
                        } else if (i > oige_number) {
                            cout << i << " is bigger then correct number" << endl;
                            cout << "Insert $1.00 and enter your number or 'q' to quit:";
                            cin >> number;
                        }
                    } else if (yesno == 'n') {

                        cout << "enter new number or quit with q";
                        cin >> number;
                    }
                }
            }
        }
    }









/*++raha;
++raha;
cout << "vihje" << endl;

    if(i < oige_number)
    {
        cout<<i<<" is smaller then correct number"<<endl;
        cin >> number;
    }
    else if (i > oige_number)
    {
        cout<<i<<" is bigger then correct number"<<endl;
        cin >> number;
    }


}
else
{
int i = stoi(number);


cout << i << endl;
if (i == oige_number)
{
cout << "sa v6itsid" << endl;
game_enabled = false;
}
else
{
    cin >> number;
    ++raha;
}
}
}}






/*if (number == "q") {
cout << "Exiting game.....Good bye" << endl;
cout << "sa kulutasid" << raha << "eurot" << endl;
game_enabled = false;
} else if (number == "hint") {
if (number == "q") {
    cout << "Exiting game.....Good bye" << endl;
    cout << "sa kulutasid " << raha << " eurot" << endl;
    game_enabled = false;
} else {
    cout << "vihje" << endl;
    cin >> number;
    int i = stoi(number);
    cout << i << endl;
    ++raha;
    ++raha;

    if (i == oige_number) {
        cout << "sa v6itsid" << endl;
        game_enabled = false;
    } else {
        cin >> number;
        ++raha;
    }
}
} else {
int i = stoi(number);
cout << i << endl;

if (i == oige_number) {
    cout << "sa v6itsid" << endl;
    game_enabled = false;
} else {
    cin >> number;
    ++raha;
}

}
}*/
