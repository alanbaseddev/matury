#include <iostream>
#include <fstream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int liczba;
    vector<int> B;
    for ( int i = 0; i < 3000; i++ ) {
        infile >> liczba;
        B.push_back(liczba);
    }
    double maxsred = 0.0;
    double sred = 0.0;
    int pocz = 0;
    int kon = 0;
    for ( int i = 0; i < 3000; i++ ) {
        for ( int j = i+50; j < 3000; j++ ) {
            sred = accumulate(B.begin() + i, B.begin() + j, 0.0) / (j-i);
            if (sred > maxsred) {
                maxsred = sred;
                pocz = i;
                kon = j;
            }
        }
    }
    cout << maxsred << endl;
    cout << kon - pocz << endl;
    cout << B[pocz] << endl;
    return 0;
}