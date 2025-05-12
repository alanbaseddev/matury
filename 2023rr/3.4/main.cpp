#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

pair<int, int> znajdzNajdluzszyRosnacoMalejacy(const vector<int>& ciag) {
    int n = ciag.size();
    int max_dlugosc = 0;
    int start = 0;

    for (int i = 0; i < n - 2; ++i) {
        int k = i + 1;
        while (k < n - 1 && ciag[k] > ciag[k - 1]) {
            k++;
        }

        if (k == i + 1) continue;

        int j = k;
        while (j < n && ciag[j] < ciag[j - 1]) {
            j++;
        }

        if (j > k) {
            int dlugosc = j - i;
            if (dlugosc > max_dlugosc) {
                max_dlugosc = dlugosc;
                start = i;
            }
        }
    }

    return {start, max_dlugosc};
}

int main() {
    ifstream infile("pi.txt");
    vector<int> liczby;
    int cyfra;
    while (infile >> cyfra) {
        liczby.push_back(cyfra);
    }

    auto [pozycja, dlugosc] = znajdzNajdluzszyRosnacoMalejacy(liczby);

    cout << pozycja + 1 << endl;
    for (int i = pozycja; i < pozycja + dlugosc; ++i) {
        cout << liczby[i];
    }
    return 0;
}