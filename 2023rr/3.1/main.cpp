#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("pi.txt");
    int licz = 0;
    int a, b;
    infile >> a;
    while ( infile >> b ) {
        int fragment = a * 10 + b;
        if (fragment > 90) {
            licz++;
        }
        a = b;
    }
    cout << licz << endl;
    return 0;
}