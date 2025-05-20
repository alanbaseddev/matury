#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("prostokaty.txt");
    struct Prostokat {
        int szer;
        int wys;
    };
    vector<Prostokat> prostokat;
    Prostokat p;
    int max = 0;
    int min;
    while ( infile >> p.szer >> p.wys ) {
        prostokat.push_back(p);
    }
    for ( const auto &p : prostokat ) {
        int pole = p.wys * p.szer;
        if ( pole > max ) {
            max = pole;
            min = max;
        }
        if ( pole < min ) {
            min = pole;
        }
    }
    cout << min << " " << max << endl;
    return 0;
}