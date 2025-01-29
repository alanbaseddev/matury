#include <iostream>
#include <fstream>
using namespace std;

int skrot(int n) {
    int m = 0;
    int r = 0;
    int b = 1;
    while (n > 0) {
        r = n % 10;
        if ( r % 2 != 0 ) {
            m += r * b;
            b *= 10;
        }
        n /= 10;
    }
    return m;
}

int main() {
    int liczba;
    int licz = 0;
    int max = 0;
    ifstream infile("skrot.txt");
    for ( int i = 0; i < 200; i++ ) {
        infile >> liczba;
        if ( skrot(liczba) == 0 ) {
            licz++;
            if ( liczba > max ) {
                max = liczba;
            }
        }
    }
    cout << max << " " << licz << endl;
    return 0;
}