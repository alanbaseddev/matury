#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("prostokaty.txt");
    struct Prostokat {
        int wys;
        int szer;
    };
    Prostokat p{};
    int najciag = 1;
    int ciag = 1;
    int ostatni;
    vector<Prostokat> prostokaty;
    while ( infile >> p.wys >> p.szer ) {
        prostokaty.push_back(p);
    }
    for ( size_t i = 1; i < prostokaty.size(); ++i ) {
       if ( prostokaty[i].wys < prostokaty[i-1].wys && prostokaty[i].szer < prostokaty[i-1].szer ) {
           ciag++;
           if ( ciag > najciag ) {
               najciag = ciag;
               ostatni = i;
           }
       }
       else {
           ciag = 1;
        }
    }
    cout << "Najdluzszy ciag: " << najciag << endl;
    cout << "Wysokosc ostatniego: " << prostokaty[ostatni].wys << endl;
    cout << "Szerokosc ostatniego: " << prostokaty[ostatni].szer << endl;
    return 0;
}