#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int liczba;
    int suma;
    int kopia;
    for ( int i = 0; i < 1000; i++ ) {
        suma = 0;
        infile >> liczba;
        kopia = liczba;
        while ( liczba > 0 ) {
            suma += liczba % 10;
            liczba /= 10;
        }
        if ( suma == 11 ) {
            cout << kopia << endl;
        }
    }
    return 0;
}
