#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int liczba;
    bool czyPierwsza;
    for ( int i = 0; i < 1000; i++ ) {
        czyPierwsza = true;
        infile >> liczba;
        for ( int n = 2; n <= sqrt(liczba); n++ ) {
            if ( liczba % n == 0 ) {
                czyPierwsza = false;
            }
        }
        if ( liczba >= 4000 && liczba <= 5000 && czyPierwsza == true ) {
            cout << liczba << endl;
        }
    }
    return 0;
}
