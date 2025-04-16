#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool CzyRosnacoMalejacy(const vector<int>& ciag) {
    int dlugosc = ciag.size();
    for (int k = 2; k <= dlugosc - 2; ++k) {
        bool rosnacy = true;
        for (int i = 1; i < k; ++i) {
            if (ciag[i] <= ciag[i-1]) {
                rosnacy = false;
                break;
            }
        }
        if (!rosnacy) continue;

        bool malejacy = true;
        for (int i = k + 1; i < dlugosc; ++i) {
            if (ciag[i] >= ciag[i-1]) {
                malejacy = false;
                break;
            }
        }
        if (malejacy) return true;
    }
    return false;
}

int main() {
    ifstream plik("pi.txt");
    vector<int> cyfry;
    int cyfra;
    while (plik >> cyfra) {
        cyfry.push_back(cyfra);
    }
    plik.close();

    int licznik = 0;
    for (size_t i = 0; i + 5 < cyfry.size(); ++i) {
        vector<int> podciag(cyfry.begin() + i, cyfry.begin() + i + 6);
        if (CzyRosnacoMalejacy(podciag)) {
            licznik++;
        }
    }

    cout << licznik;

    return 0;
}