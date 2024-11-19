#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int liczba;
    int nieparzysta = 1;
    for ( int i = 0; i < 1000; i++ ) {
        infile >> liczba;
        if ( liczba & 2 != 0 ) {
            nieparzysta++;
        }
    }
    cout << "Liczb nieparzystych jest: " << nieparzysta;
    return 0;
}
