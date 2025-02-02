#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> rozklad(int liczba) {       //rozklada liczby z pierwszego wiersza na czynniki
    vector<int> czynniki;
    while ( liczba % 2 == 0 ) {
        czynniki.push_back(2);
        liczba /= 2;
    }
    for ( int i = 3; i * i <= liczba; i += 2 ) {
        while ( liczba % i == 0 ) {
            czynniki.push_back(i);
            liczba /= i;
        }
    }
    if ( liczba > 2 ) {
        czynniki.push_back(liczba);
    }
    return czynniki;
}

void wczytajWiersz(const string& line, vector<int>& liczby) {      // wczytuje wiersz z pliku
    istringstream iss(line);
    int n;
    while ( iss >> n ) {
        liczby.push_back(n);
    }
}

int main() {
    vector<int> liczby;
    vector<int> liczby2;
    ifstream infile("liczby.txt");
    string line;
    if ( getline( infile, line ) ) {
        wczytajWiersz(line, liczby);
    }
    if ( getline( infile, line ) ) {
        wczytajWiersz(line, liczby2);
    }         // wczytanie obu wierszy
    unordered_map<int, int> liczby_map;
    for ( int liczba : liczby ) {
        vector<int> czynniki = rozklad(liczba);
        for ( int czynnik : czynniki ) {
            liczby_map[czynnik]++;
        }
    }
    for ( int liczba : liczby2 ) {
        unordered_map<int, int> czynniki_map;
        vector<int> czynniki_rozklad = rozklad(liczba);
        bool mozna = true;
        for ( int czynnik : czynniki_rozklad ) {
            czynniki_map[czynnik]++;
            if ( czynniki_map[czynnik] > liczby_map[czynnik] ) {
                mozna = false;
                break;
            }
        }
        if ( mozna ) {
            cout << liczba << endl;
        }
    }
    return 0;

}
