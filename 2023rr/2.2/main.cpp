#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int licz(int n) {
    int nast;
    int pop = n % 2;
    int li = 1;
    n = n / 2;
    while ( n > 0 ) {
        nast = n % 2;
        if ( nast != pop ) {
            li++;
            pop = nast;
        }
        n = n / 2;
    }
    return li;
}

int main() {
    ifstream infile("bin.txt");
    string n;
    int i = 0;
    while ( infile >> n ) {
        if ( licz( stoi(n, nullptr, 2) ) <= 2 ) {
            i++;
        }
    }
    cout << i;
    return 0;
}