#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool rozklad(int liczba, int A[]) {
    int pocz = liczba;
    int wynik = 1;
    for ( int i = 0; i < 3000; i++ ) {
        if ( liczba % A[i] == 0 ) {
            liczba = liczba / A[i];
            wynik *= A[i];
        }
    }
    return wynik == pocz;
}


int main() {
    ifstream infile("liczby.txt");
    int A[3000];
    int B[20];
    for ( int i = 0; i < 3000; i++) {
        infile >> A[i];
    }
    for ( int i = 0; i < 20; i++) {
        infile >> B[i];
        if (rozklad(B[i], A)) {
            cout << B[i] << endl;
        }
    }

    return 0;

}
