#include <iostream>

int skrot( int n ) {
    int m;
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

int main() {

    return 0;
}