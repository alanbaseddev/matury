#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <format>

long long trojkowy(const std::string &s) {
    long long wartosc = 0;
    for (char c : s) {
        int liczba;
        if (c == 'o') liczba = 0;
        else if (c == '+') liczba = 1;
        else liczba = 2;
        wartosc = wartosc * 3 + liczba;
    }
    return wartosc;
}

int main() {
    std::ifstream infile("symbole.txt");
    std::vector<std::string> wiersze;
    std::string s;
    while (infile >> s) {
        wiersze.push_back(s);
    }
    long long max = 0;
    std::string maxs;
    for (auto &str : wiersze) {
        long long wartosc = trojkowy(str);
        if (wartosc > max) {
            max = wartosc;
            maxs = str;
        }
    }
    std::cout << max << std::endl;
    std::cout << maxs << std::endl;

    return 0;
}