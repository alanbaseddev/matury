#include <algorithm>
#include <iostream>
#include <fstream>
#include <bits/ranges_algo.h>
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int n;
    int mniejsze = 0, wieksze = 0, rowne = 0;
    while (infile >> n) {
        string s = to_string(n);
        string najw = s;
        string najm = s;
        sort(najw.begin(), najw.end(), greater<char>());
        sort(najm.begin(), najm.end());
        int max = stoi(najw);
        int min = stoi(najm);
        int roznica = max - min;
        if ( roznica < n ) mniejsze++;
        else if ( roznica > n ) wieksze++;
        else {
            rowne++;
            cout << "Rowna: " << n << endl;
        }
    }
    cout << "Mniejsza: " << mniejsze << endl;
    cout << "Wieksza: " << wieksze << endl;

    return 0;
}