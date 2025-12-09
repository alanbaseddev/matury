#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream infile("symbole.txt");
    std::string s;
    std::vector<std::string> wiersze;
    while (infile >> s) {
        wiersze.push_back(s);
    }
    int n = wiersze.size();
    int m = wiersze[0].size();
    std::vector<std::pair<int,int>> wyniki;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-2; j++) {
            char c = wiersze[i][j];
            bool ok = true;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (wiersze[i+x][j+y] != c) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                wyniki.emplace_back(i+2, j+2);
            }
        }
    }
    std::cout << "Liczba kwadratow: " << wyniki.size() << std::endl;
    for (auto &p : wyniki) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}