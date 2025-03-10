#include <iostream>
#include <fstream>
#include <vector>
#include <numeric> // dla std::accumulate
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int liczba;
    vector<int> B;
    for (int i = 0; i < 3000; i++) {
        infile >> liczba;
        B.push_back(liczba);
    }

    double maxsred = 0.0;
    int pocz = 0;
    int kon = 0;

    for (int i = 0; i < 3000 - 50; i++) {
        double sum = accumulate(B.begin() + i, B.begin() + i + 50, 0.0);
        for (int j = i + 50; j < 3000; j++) {
            sum += B[j];
            double sred = sum / (j - i + 1);
            if (sred > maxsred) {
                maxsred = sred;
                pocz = i;
                kon = j;
            }
        }
    }

    cout << "Maksymalna srednia: " << maxsred << endl;
    cout << "Dlugosc przedzialu: " << kon - pocz + 1 << endl;
    cout << "Pierwszy element przedzialu: " << B[pocz] << endl;

    return 0;
}
