#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

bool czyPier(int n) {
    for ( int i = 2; i * i <= n; i++ ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    return true;
}

int rozklad(int n) {
    vector<int> dzielniki;
    for ( int i = 2; i * i <= n; i++ ) {
        if ( czyPier(i) && n % i == 0 ) {
            dzielniki.push_back(i);
            while ( n % i == 0 ) n /= i;
        }
    }
    if (n > 1) dzielniki.push_back(n);
    return dzielniki.size();
}

int main() {
    ifstream infile("liczby.txt");
    int n;
    while (infile >> n) {
        if ( rozklad(n) >= 5 ) {
            cout << n << endl;
        }
    }
    return 0;
}