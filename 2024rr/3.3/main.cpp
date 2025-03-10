#include <iostream>
#include <fstream>
using namespace std;

int skrot( int n ) {
    int m = 0;
    int r = 0;
    int b = 1;
    while ( n > 0 ) {
        r = n % 10;
        if ( r % 2 != 0 ) {
            m += r * b;
            b *= 10;
        }
        n /= 10;
    }
    return m;
}

int NWD( int a, int b ) {
    while ( a != b ) {
        if ( a > b ) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}


int main() {
    ifstream infile("skrot2.txt");
    int n;
    while ( infile >> n ) {
        if ( NWD(n, skrot(n)) == 7 ) {
            cout << n << endl;
        }
    }
    return 0;
}
