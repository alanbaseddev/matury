#include <algorithm>
#include <iostream>
#include <fstream>
#include <bits/ranges_algo.h>
using namespace std;

int main() {
    int liczba[3000];
    ifstream infile("liczby.txt");
    for ( int i=0; i<3000; i++ ) {
        infile >> liczba[i];
        sort(liczba, liczba + 3000, greater<int>());
    }
    cout << liczba[100];
    return 0;
}