#include <iostream>
#include <fstream>
using namespace std;

string toBinary(int liczba) {
    string a;
    while (liczba > 0) {
        a = (char)(liczba % 2 + '0') + a;
        liczba = liczba / 2;
    }
    return a;
}

int main() {
    ifstream infile("bin.txt");
    string n;
    int a;
    int max;
    while ( infile >> n ) {
        a = stoi(n, nullptr, 2);
        if ( a > max ) {
            max = a;
        }
    }
    cout << toBinary(max) << endl;
    return 0;
}