#include <iostream>
using namespace std;

int main() {
    int i;
    int n=5;
    int a[100];
    int odd=0;
    int even=0;
    cout << "enter your 5 numbers"<<endl;

    for(i=0; i<n; i++){
        cin>>a[i];
    }
    cout<< "\nODD Numbers:"<<endl;
    for(i=0;i<n;i++){
        if(a[i]%2==1) {
            cout << " " << a[i];
            odd++;
        }
    }
    cout<< "\nEVEN Numbers:"<<endl;
    for(i=0; i<n; i++){
        if(a[i]%2==0)
        {
            cout << " " << a[i];
            even++;
        }

    }
    cout<<"\nThere was "<<odd<<" odd numbers and "<<even<<" even numbers"<<endl;
}